//
// Created by Sandro on 23.02.2016.
//

#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Tree {
private:
    Tree *root;
    Tree *rTree;
    Tree *lTree;
    int value;
    char character;

public:
    Tree(Tree *root, Tree *rightTree, Tree *leftTree, int v, char c);
    Tree *getRoot();
    Tree *getRightTree();
    Tree *getLeftTree();
    int getValue();
    char getCharacter();
    void setRoot(Tree *);
    string toString();

    bool isLeaf();
};


#endif //HUFFMAN_TREE_H
