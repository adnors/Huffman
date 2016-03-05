//
// Created by Sandro on 05.03.2016.
//

#ifndef HUFFMAN_CODE_H
#define HUFFMAN_CODE_H

#include <fstream>
#include <list>
#include "Tree.h"

class Code {
protected:
    string line = "";
    list<Tree *> trees;
    char *inputfile;
    char *outputfile;
    ifstream input;
    ofstream output;

    void buildTree();

public:
    virtual void doCode() = 0;
};


#endif //HUFFMAN_CODE_H
