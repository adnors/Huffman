//
// Diese Klasse komprimiert die Datei an der Stelle input und gibt die neue Datei an der Stelle ouput aus.
// Zum komprimieren muss die Methode doCode() gestartet werden.
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
void Encode::doCode() {
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
                character = (int) line[i];
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
    string line;
    list<bool> code;
    if (input.is_open()) {
        getline(input, line);
        for (unsigned int i = 0; i < line.length(); i++) {
            code.splice(code.end(), getCharCode(getCharTree(trees.front(), line[i])));
        }
    }
    return code;
}

void Encode::writeCode() {
    input.open(inputfile);
    if (output.is_open() && input.is_open()) {
        while (!input.eof()) {
            list<bool> code = getCode();
            string out = "";
            int outLength = 0;
            bool itNotEnd = true;
            for (list<bool>::iterator it = code.begin(); itNotEnd;) {
                char c = 0;
                for (int i = 0; i < 8; i++, it++) {
                    c <<= 1;
                    if (it == code.end()) {
                        itNotEnd = false;
                    }
                    if (itNotEnd) {
                        c |= *it;
                        outLength++;
                    }
                }
                out += c;
            }
            output << outLength << out << '\n';
        }
    }
}

void Encode::writeTree() {
    for (int i = 0; i < NMBR_CHARS; i++) {
        if (cntChar[i] != 0) {
            output << (char) (i + 32) << cntChar[i];
        }
    }
    output << '\n';
}

/**
 * @brief Schreibt die Ausgabedatei
 * @return void
 */
void Encode::writeFile() {
    output.open(outputfile, ios::binary);
    writeTree();
    writeCode();
    output.close();
}