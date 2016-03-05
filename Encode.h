//
// Created by Sandro on 23.02.2016.
//

#ifndef HUFFMAN_ENCODE_H
#define HUFFMAN_ENCODE_H
#define NMBR_CHARS 95

#include <string>
#include <fstream>
#include <list>
#include "Tree.h"

using namespace std;

class Encode {
private:
    int totalchar = 0;
    int cntdiffchar = 0;
    int cntchar[NMBR_CHARS] = {0};
    int character = 0;
    string line = "";
    char *inputfile;
    char *outputfile;
    ifstream input;
    ofstream output;
    list<Tree *> trees;

public:
    Encode(char *, char *);
    void doEncode();
    void getcntchar();

    void buildLeaves();

    void buildTree();
    Tree *getCharTree(Tree *, char);

    list<bool> getCharCode(Tree *);

    list<bool> getCode();
    void writeFile();
};


#endif //HUFFMAN_ENCODE_H
