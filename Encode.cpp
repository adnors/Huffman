//
// Created by Sandro on 23.02.2016.
//

#include "Encode.h"

using namespace std;

Encode::Encode(ifstream *f) { //Der Encode-Methode wird eine Datei übergeben, die das zu komprimierende Dateimaterial enthält
    file = f;
}

void Encode::doEncode() { //Hier geschieht die eigentliche Komprimierung.
    getcntchar();
    list<Tree> trees2;
    Tree *trees[cntdiffchar];
    buildLeaves(trees, trees2);
    buildTree(trees);
}

void Encode::getcntchar() { //Zählt die Anzahl der Zeichen in der Datei
    while (!file->eof()) {
        getline(*file, line);
        for (unsigned int i = 0; i < line.length(); i++) {
            character = (int) line.at(i);
            if (cntchar[character - 32] == 0) {
                cntdiffchar++;
            }
            cntchar[character - 32]++;
            totalchar++;
        }
    }
}

void Encode::buildLeaves(Tree *trees[], list<Tree> trees2) { //Erzeugt die einzelnen Knoten des Baums, einen pro unterschiedlichem Zeichen
    int j = 0;
    for (int i = 0; i < CNT_CHAR && j < cntdiffchar; i++) {
        if (cntchar[i] != 0) {
            trees2.
            trees[j] = new Tree((Tree *) NULL, (Tree *) NULL, cntchar[i], (char) i + 32);
            j++;
        }
    }
}

void Encode::buildTree(Tree *trees[]) { //Fügt die separaten Knoten zu einem Baum zusammen.

}

int Encode::getminvalue(int *minvaluei) { //Gibt das kleinste gefundene Zeichen als ASCII-Wert zurück
    int i = 0;
    int minvalue;
    do {
        minvalue = cntchar[i];
        *minvaluei = i;
        i++;
    } while (minvalue != 0);
    for (i; i < CNT_CHAR - 1; i++) {
        if (cntchar[i] != 0 && cntchar[i] < minvalue) {
            minvalue = cntchar[i];
            *minvaluei = i;
        }
    }
    cntchar[*minvaluei] = 0;
    return minvalue;
}