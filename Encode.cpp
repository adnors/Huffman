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
    int minValue = getminvalue(0);
    int minValue2 = getminvalue(minValue);

}

int Encode::getminvalue(int start) {
    int i = 0;
    int minValue = cntchar[i];
    while (minValue != 0 && i < CNT_CHAR - 1) {
        if (cntchar[i] < minValue && start <= minValue) {
            minValue = cntchar[i];
        }
        i++;
    }
    return minValue;
}