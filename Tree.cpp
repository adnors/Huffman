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

string Tree::toString() { //gibt die wichtigsten Attribute eines Knotens als String aus
    stringstream sstream;
    sstream << "Wert: " << this->getValue() << " Char: " << this->getCharacter() << endl;
    if (lTree != NULL) {
        sstream << "linker Teilbaum: " << lTree->toString();
    }
    if (rTree != NULL) {
        sstream << "rechter Teilaum: " << rTree->toString();
    }
    string ret = sstream.str();
    return ret;
}

bool Tree::leaf() { //ermittelt, ob ein Knoten ein Blatt ist oder nicht
    bool retvalue = false;
    if (rTree == NULL && lTree == NULL) {
        retvalue = true;
    }
    return retvalue;
}