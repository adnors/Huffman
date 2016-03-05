//
// Created by Sandro on 05.03.2016.
//

#include "Code.h"

/**
 * @brief Erzeugt den Baum
 * @return void
 */
void Code::buildTree() {
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
