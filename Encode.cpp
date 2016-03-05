//
// Diese Klasse komprimiert die Datei an der Stelle input und gibt die neue Datei an der Stelle ouput aus.
// Zum komprimieren muss die Methode doEncode() gestartet werden.
// Created by Sandro on 23.02.2016.
//

#include "Encode.h"

using namespace std;

Encode::Encode(char *i, char *o) {
    inputfile = i;
    outputfile = o;
}

/**
 * @brief Diese Methode enkodiert die Datei.
 * @param
 * @return void
 *
 */
void Encode::doEncode() {
    getcntchar();
    list<Tree *> trees;
    buildLeaves(&trees);
    buildTree(&trees);
    for (list<Tree *>::iterator it = trees.begin(); it != trees.end(); it++) {
        cout << (*it)->toString();
    }
    writeFile();
    //output.open(outputfile, ios::out);
}

/**
 *
 */
void Encode::getcntchar() {
    input.open(inputfile, ios::in);
    if (input.is_open()) {
        while (!input.eof()) {
            getline(input, line);
            for (unsigned int i = 0; i < line.length(); i++) {
                character = (int) line.at(i);
                if (cntchar[character - 32] == 0) {
                    cntdiffchar++;
                }
                cntchar[character - 32]++;
                totalchar++;
            }
        }
        input.close();
    }
}

void Encode::buildLeaves(list<Tree *> *trees) {
    for (int i = 0; i < NMBR_CHARS; i++) {
        if (cntchar[i] != 0) {
            Tree *newTree = new Tree(nullptr, nullptr, nullptr, cntchar[i], (char) (i + 32));
            trees->push_back(newTree);
        }
    }
    trees->sort([](Tree *first, Tree *second) { return first->getValue() < second->getValue(); });
}

void Encode::buildTree(list<Tree *> *trees) {
    list<Tree *>::iterator it;
    while (trees->size() > 1) {
        it = trees->begin();
        Tree *oldTree1 = *it++;
        Tree *oldTree2 = *it++;
        trees->erase(trees->begin(), it);
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
        trees->push_back(newTree);
        trees->sort([](Tree *first, Tree *second) { return first->getValue() < second->getValue(); });
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

list<bool> Encode::encodeChar(Tree *tree) {
    list<bool> code;
    Tree *root = tree->getRoot();
    if (root->getRoot() != nullptr) {
        code = encodeChar(root);
        code.push_back(root->getLeftTree() != tree); // linker Teilbaum -> 0 ; rechter Teilbaum -> 1;
    } else {
        code.push_back(root->getLeftTree() != tree); // linker Teilbaum -> 0 ; rechter Teilbaum -> 1;
    }
    return code;
}

void Encode::writeFile() {

}