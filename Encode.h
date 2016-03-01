//
// Created by Sandro on 23.02.2016.
//

#ifndef HUFFMAN_ENCODE_H
#define HUFFMAN_ENCODE_H
#define CNT_CHAR 95

#include <string>
#include <fstream>

using namespace std;

class Encode {
private:
    int totalchar;
    int cntdiffchar;
    int cntchar[CNT_CHAR];
    int character;
    string line;
    ifstream *file;

public:
    Encode(ifstream *);
    string doEncode();

    void getcntchar();
    void buildTree();

    int getminvalue();

};


#endif //HUFFMAN_ENCODE_H
