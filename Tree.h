//
// Created by Sandro on 23.02.2016.
//

#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include <string>

class Tree {
private:
    Tree *rTree;
    Tree *lTree;
    int value;
    char character;

public:
    Tree(Tree *rightTree, Tree *leftTree, int v, char c = '');
    Tree *getRightTree();
    Tree *getLeftTree();
    int getValue();
    char getCharacter();

    string toString();
    bool leaf();
};


#endif //HUFFMAN_TREE_H
