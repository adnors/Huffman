//
// Created by Sandro on 05.03.2016.
//

#include "Decode.h"

Decode::Decode(char *i, char *o) {
    inputfile = i;
    outputfile = o;
}

void Decode::doCode() {
    input.open(inputfile);
    parseTree();
    buildTree();
    parseText();
    input.close();
}

void Decode::parseTree() {
    if (input.is_open()) {
        char c;
        int v;
        while (input.peek() != '\n') {
            input >> c;
            input >> v;
            trees.push_back(new Tree(nullptr, nullptr, nullptr, v, c));
        }
        input.read(&c, 1);
    }
}

void Decode::parseText() {
    if (input.is_open()) {
        output.open(outputfile);
        if (output.is_open()) {
            while (!input.eof()) {
                Tree *tree = trees.front();
                getline(input, line);
                for (int i = 0; i < line.length(); i++) {
                    char c = line[i];
                    for (int j = 0; j < 8; j++) {
                        bool right = (bool) ((c >> (8 - j)) & 1);
                        tree = right ? tree->getRightTree() : tree->getLeftTree();
                        if (tree->isLeaf()) {
                            output << tree->getCharacter();
                            tree = trees.front();
                        }
                    }
                }
                output << endl;
            }
            output.close();
        }
    }
}