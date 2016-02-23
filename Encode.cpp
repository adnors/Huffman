//
// Created by Sandro on 23.02.2016.
//

#include "Encode.h"

using namespace std;

Encode::Encode(ifstream *f) {
    datei = f;
}

string Encode::doEncode() {
    getAnzahl();
    buildTree();
}

void Encode::getAnzahl() {
    while (!datei->eof()) {
        getline(*datei, zeile);
        for (int i = 0; i < zeile.length(); i++) {
            buchstabe = (int) zeile.at(i);
            anzahl[buchstabe - 32]++;
            gesamt++;
        }
    }
}

void Encode::buildTree() {

}

int Encode::getMinValue() {
    int i = 0;
    int minValue = anzahl[i];
    while (minValue != 0 && i < ANZAHL_ZEICHEN - 1) {
        i++;
        if (anzahl[i] < minValue) {
            minValue = anzahl[i];
        }
    }
    return minValue;
}