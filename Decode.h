//
// Created by Sandro on 05.03.2016.
//

#ifndef HUFFMAN_DECODE_H
#define HUFFMAN_DECODE_H

#include <fstream>

using namespace std;

class Decode {
private:
    char *inputfile;
    char *outputfile;
    ifstream input;
    ofstream output;

public:
    Decode(char *, char *);

    void doDecode();
};


#endif //HUFFMAN_DECODE_H
