//
// Diese Klasse komprimiert die Datei an der Stelle input und gibt die neue Datei an der Stelle ouput aus.
// Zum komprimieren muss die Methode doEncode() gestartet werden.
// Created by Sandro on 23.02.2016.
//

#include "Encode.h"

using namespace std;
/**
 * @brief Diese Methode speichert Ein- bzw. Ausgabedatei.
 * @param
 * @return Encode
 *
 */
Encode::Encode(char *i, char *o) {
    inputfile = i;
    outputfile = o;
}

/**
 * @brief Diese Methode enkodiert die Datei.
 * @param
 * @return void
 * Die Encode-Methode zählt die Zeichen der Eingabedatei, erstellt die entsprechenden Knoten und schließlich den fertigen Baum
 */
void Encode::doEncode() {
    getCntChar();
    buildLeaves();
    buildTree();
    /*for (list<Tree *>::iterator it = trees.begin(); it != trees.end(); it++) {  //Zum Testen der Baumstruktur
        cout << (*it)->toString();
    }*/
    writeFile();
}

/**
 * @brief Zählt die Zeichen der Eingabedatei
 * @return void
 */
void Encode::getCntChar() {
    input.open(inputfile);
    if (input.is_open()) {
        while (!input.eof()) {
            getline(input, line);
            for (unsigned int i = 0; i < line.length(); i++) {
                character = (int) line.at(i);
                if (cntChar[character - 32] == 0) {
                    cntdiffchar++;
                }
                cntChar[character - 32]++;
                totalchar++;
            }
        }
        input.close();
    }
}

/**
 * @brief Erzeugt die Knoten des Baums
 * @return void
 */
void Encode::buildLeaves() {
    for (int i = 0; i < NMBR_CHARS; i++) {
        if (cntChar[i] != 0) {
            Tree *newTree = new Tree(nullptr, nullptr, nullptr, cntChar[i], (char) (i + 32));
            trees.push_back(newTree);
        }
    }
    trees.sort([](Tree *first, Tree *second) { return first->getValue() < second->getValue(); });
}

/**
 * @brief Erzeugt den Baum
 * @return void
 */
void Encode::buildTree() {
    list<Tree *>::iterator it;
    while (trees.size() > 1) {
        it = trees.begin();
        Tree *oldTree1 = *it++;
        Tree *oldTree2 = *it++;
        trees.erase(trees.begin(), it);
        Tree *newTree;
        if (oldTree1->getValue() <= oldTree2->getValue()) {
            newTree = new Tree(nullptr, oldTree1, oldTree2, oldTree1->getValue() + oldTree2->getValue(), (char) 0);
            oldTree1->setRoot(newTree);
            oldTree2->setRoot(newTree);
        } else {
            newTree = new Tree(nullptr, oldTree2, oldTree1, oldTree1->getValue() + oldTree2->getValue(), (char) 0);
            oldTree1->setRoot(newTree);
            oldTree2->setRoot(newTree);
        }
        trees.push_back(newTree);
        trees.sort([](Tree *first, Tree *second) { return first->getValue() < second->getValue(); });
    }
}

Tree *Encode::getCharTree(Tree *root, char c) {
    Tree *charTree;
    if (root->isLeaf() && root->getCharacter() == c) {
        charTree = root;
    } else {
        if (root->isLeaf() && root->getCharacter() != c) {
            charTree = nullptr;
        } else {
            charTree = getCharTree(root->getLeftTree(), c);
            if (charTree == nullptr) {
                charTree = getCharTree(root->getRightTree(), c);
            }
        }
    }
    return charTree;
}

list<bool> Encode::getCharCode(Tree *tree) {
    list<bool> code;
    Tree *root = tree->getRoot();
    if (root->getRoot() != nullptr) {
        code = getCharCode(root);
        code.push_back(root->getLeftTree() != tree); // linker Teilbaum -> 0 ; rechter Teilbaum -> 1;
    } else {
        code.push_back(root->getLeftTree() != tree); // linker Teilbaum -> 0 ; rechter Teilbaum -> 1;
    }
    return code;
}

list<bool> Encode::getCode() {
    input.open(inputfile);
    string line;
    list<bool> code;
    if (input.is_open()) {
        while (!input.eof()) {
            getline(input, line);
            for (unsigned int i = 0; i < line.length(); i++) {
                code.splice(code.end(), getCharCode(getCharTree(trees.front(), line.at(i))));
            }
        }
        input.close();
    }
    return code;
}

void Encode::writeCode() {
    list<bool> code = getCode();
    if (output.is_open()) {
        for (list<bool>::iterator it = code.begin(); it != code.end(); it++) {
            char c = 0;
            for (int i = 0; i < 8 && it != code.end(); i++, it++) {
                c |= *it;
                c <<= 1;
            }
            output.write(&c, 1);
        }
    }
}

void Encode::writeTree() {

}

/**
 * @brief Schreibt die Ausgabedatei
 * @return void
 */
void Encode::writeFile() {
    output.open(outputfile);
    writeTree();
    writeCode();
    output.close();
}