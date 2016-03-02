//
// Created by Sandro on 23.02.2016.
//

#ifndef HUFFMAN_ENCODE_H
#define HUFFMAN_ENCODE_H
#define CNT_CHAR 95

#include <string>
#include <fstream>
#include <list>
#include "Tree.h"

using namespace std;

class Encode {
private:
    int totalchar = 0;
    int cntdiffchar = 0;
    int cntchar[CNT_CHAR] = {0};
    int character = 0;
    string line = "";
    ifstream *file;

public:
    Encode(ifstream *);

    void doEncode();

    void getcntchar();


    void buildLeaves(list<Tree> *trees);

    void buildTree(list<Tree> *trees);

    int getminvalue(int *minvaluei);

};


#endif //HUFFMAN_ENCODE_H
