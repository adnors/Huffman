//
// Created by Sandro on 23.02.2016.
//

#ifndef HUFFMAN_ENCODE_H
#define HUFFMAN_ENCODE_H
#define ANZAHL_ZEICHEN 95

#include <string>
#include <fstream>

using namespace std;

class Encode {
private:
    int gesamt;
    int anzahl[ANZAHL_ZEICHEN];
    int buchstabe;
    string zeile;
    ifstream *datei;

public:
    Encode(ifstream *);
    string doEncode();
    void getAnzahl();
    void buildTree();
    int getMinValue();

};


#endif //HUFFMAN_ENCODE_H
