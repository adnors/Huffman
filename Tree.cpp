//
// Created by Sandro on 23.02.2016.
//

#include "Tree.h"

Tree::Tree(Tree *rightTree, Tree *leftTree, int v, char c) {
    rTree = rightTree;
    lTree = leftTree;
    value = v;
    character = c;
}

Tree *Tree::getRightTree() {
    return rTree;
}

Tree *Tree::getLeftTree() {
    return lTree;
}

int Tree::getValue() {
    return value;
}

char Tree::getCharacter() {
    return character;
}

void Tree::toString() {
    cout << "Wurzel: " << endl << "Wert: " << this->getValue() << " Char: " << getCharacter() << endl;
}

bool Tree::leaf() {
    bool retvalue = false;
    if (rTree == NULL && lTree == NULL) {
        retvalue = true;
    }
    return retvalue;
}