//
// Created by Sandro on 23.02.2016.
//

#include "Encode.h"

using namespace std;

Encode::Encode(ifstream *f) {
    file = f;
}

string Encode::doEncode() {
    getcntchar();
    buildTree();
}

void Encode::getcntchar() {
    while (!file->eof()) {
        getline(*file, line);
        for (int i = 0; i < line.length(); i++) {
            character = (int) line.at(i);
            if (cntchar[character - 32] == 0) {
                cntdiffchar++;
            }
            cntchar[character - 32]++;
            totalchar++;
        }
    }
}

void Encode::buildTree() {
    int minValue = getminvalue();
    int minValue2 = getminvalue();

}

int Encode::getminvalue() {
    int i = 0;
    int minvalue;
    int minvaluei;
    do {
        minvalue = cntchar[i];
        minvaluei = i;
        i++;
    } while (minvalue != 0);
    for (i; i < CNT_CHAR - 1; i++) {
        if (cntchar[i] != 0 && cntchar[i] < minvalue) {
            minvalue = cntchar[i];
            minvaluei = i;
        }
    }
    cntchar[minvaluei] = 0;
    return minvalue;
}