//
// Created by Sandro on 23.02.2016.
//

#include "Encode.h"

using namespace std;

Encode::Encode(char *i, char *o) {
    inputfile = i;
    outputfile = o;
    output.open(outputfile, ios::out | ios::binary | ios::trunc);
}

/**
 * @brief Diese Methode
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
    for (int i = 0; i < CNT_CHAR; i++) {
        if (cntchar[i] != 0) {
            Tree *newTree = new Tree((Tree *) NULL, (Tree *) NULL, cntchar[i], (char) (i + 32));
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
            newTree = new Tree(oldTree1, oldTree2, oldTree1->getValue() + oldTree2->getValue(), (char) 0);
        } else {
            newTree = new Tree(oldTree2, oldTree1, oldTree1->getValue() + oldTree2->getValue(), (char) 0);
        }
        trees->push_back(newTree);
        trees->sort([](Tree *first, Tree *second) { return first->getValue() < second->getValue(); });
    }
}