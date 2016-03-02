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

Tree *Tree::getRightTree() { //gibt den rechten Teilbaum zurück
    return rTree;
}

Tree *Tree::getLeftTree() { //gibt den linken Teilbaum zurück
    return lTree;
}

int Tree::getValue() { //gibt den Wert des Knotens zurück
    return value;
}

char Tree::getCharacter() { //gibt das Zeichen des Knotens zurück
    return character;
}

void Tree::toString() { //gibt die wichtigsten Attribute eines Knotens als String aus
    cout << "Wurzel: " << endl << "Wert: " << this->getValue() << " Char: " << getCharacter() << endl;
}

bool Tree::leaf() { //ermittelt, ob ein Knoten ein Blatt ist oder nicht
    bool retvalue = false;
    if (rTree == NULL && lTree == NULL) {
        retvalue = true;
    }
    return retvalue;
}