/**
 * @author Sandro Käppner, Daniel Hänsler
 */


#include "Code.h"

/**
 * @brief Konstruiert den Baum aus den Buchstaben, sie im Text vorkommen.
 * @return void
 *
 *
 */
void Code::buildTree() {
    list<Tree *>::iterator it; // Iterator um die Liste durchzugehen
    while (trees.size() > 1) { // Solange mehr als ein Baum in der Liste ist:
        it = trees.begin(); // Iterator auf den Anfang der Liste setzen
        Tree *oldTree1 = *it++; // Die beiden Teilbäume mit der kleinsten Häufigkeit speichern
        Tree *oldTree2 = *it++;
        trees.erase(trees.begin(), it); // und aus der Liste entfernen
        Tree *newTree;
        if (oldTree1->getValue() >= oldTree2->getValue()) {
            newTree = new Tree(nullptr, oldTree1, oldTree2, oldTree1->getValue() + oldTree2->getValue(), (char) 0);
            oldTree1->setRoot(newTree);
            oldTree2->setRoot(newTree);
        } else {
            newTree = new Tree(nullptr, oldTree2, oldTree1, oldTree1->getValue() + oldTree2->getValue(), (char) 0);
            oldTree1->setRoot(newTree);
            oldTree2->setRoot(newTree);
        }
        trees.push_back(newTree); // neuen Baum in die Liste schreiben
        trees.sort([](Tree *first, Tree *second) {
            return first->getValue() < second->getValue();
        }); // Die Liste sortieren
    }
}
