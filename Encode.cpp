//
// Created by Sandro on 23.02.2016.
//

#include "Encode.h"

using namespace std;

Encode::Encode(ifstream *f) {
    file = f;
}

void Encode::doEncode() {
    getcntchar();
    list<Tree> trees;
    buildLeaves(&trees);
    for (list<Tree>::iterator it = trees.begin(); it != trees.end(); it++) {
        it->toString();
    }
    //buildTree(trees);
}

void Encode::getcntchar() {
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

void Encode::buildLeaves(list<Tree> *trees) {
    for (int i = 0; i < CNT_CHAR; i++) {
        if (cntchar[i] != 0) {
            const Tree *newTree = new Tree((Tree *) NULL, (Tree *) NULL, cntchar[i], (char) (i + 32));
            trees->push_back(*newTree);
        }
    }
    trees->sort([](Tree first, Tree second) { return first.getValue() < second.getValue(); });
}

void Encode::buildTree(list<Tree> *trees) {
    list<Tree>::iterator it;
    while (trees->size() <= 1) {
        it = trees->begin();
        Tree oldTree1 = *it;
    }
}

int Encode::getminvalue(int *minvaluei) {
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