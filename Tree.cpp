/**
 * @author Sandro Käppner, Daniel Hänsler
 */


#include "Tree.h"

Tree::Tree(Tree *r, Tree *rightTree, Tree *leftTree, int v, char c) {
    root = r;
    rTree = rightTree;
    lTree = leftTree;
    value = v;
    character = c;
}
/**
 * @brief Gibt die Wurzel des Baums zurück
 * @return Tree
 */
Tree *Tree::getRoot() {
    return root;
}
/**
 * @brief Gibt den rechten Teilbaum zurück
 * @return Tree
 */
Tree *Tree::getRightTree() {
    return rTree;
}
/**
 * @brief Gibt den linken Teilbaum zurück
 * @return Tree
 */
Tree *Tree::getLeftTree() {
    return lTree;
}
/**
 * @brief Gibt den Wert des Knotens zurück
 * @return int
 */
int Tree::getValue() {
    return value;
}
/**
 * @brief Gibt das Zeichen des Knotens zurück
 * @return char
 */
char Tree::getCharacter() {
    return character;
}
/**
 * @brief Bestimmt den Knoten zur Wurzel
 * @return void
 */
void Tree::setRoot(Tree *r) {
    root = r;
}
/**
 * @brief Gibt den Baum in der Konsole aus
 * @return string
 */
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
/**
 * @brief Gibt Information darüber, ob ein Knoten ein Blatt ist oder nicht
 * @return bool
 */
bool Tree::isLeaf() { //ermittelt, ob ein Knoten ein Blatt ist oder nicht
    bool retvalue = false;
    if (rTree == nullptr && lTree == nullptr) {
        retvalue = true;
    }
    return retvalue;
}