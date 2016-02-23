//
// Created by Sandro on 23.02.2016.
//

#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H


class Tree {
private:
    Tree *rTree;
    Tree *lTree;
    int value;
    char character;

public:
    Tree(Tree *, Tree *, int, char);

    Tree *getRightTree();

    Tree *getLeftTree();

    int getValue();

    char getCharacter();

    bool leaf();


};


#endif //HUFFMAN_TREE_H
