/**
 * @author Sandro Käppner, Daniel Hänsler
 */


#ifndef HUFFMAN_DECODE_H
#define HUFFMAN_DECODE_H

#include "Code.h"

using namespace std;

class Decode : public Code {
private:
    void parseTree();
    void parseText();

public:
    Decode(char *, char *);
    void doCode();
};


#endif //HUFFMAN_DECODE_H
