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
        trees.sort([](Tree *first, Tree *second) { return first->getValue() < second->getValue(); });
        input.read(&c, 1);
    }
}

void Decode::parseText() {
    if (input.is_open()) {
        output.open(outputfile);
        if (output.is_open()) {
            while (!input.eof()) {
                Tree *tree = trees.front();
                int length;
                input >> length;
                getline(input, line);
                for (int i = 0; i < line.length(); i++) {
                    char c = line[i];
                    for (int j = 0; j < 8 && j < length; j++) {
                        bool right = (bool) ((c >> (7 - j)) & 1);
                        tree = right ? tree->getRightTree() : tree->getLeftTree();
                        if (tree->isLeaf()) {
                            output << tree->getCharacter();
                            tree = trees.front();
                        }
                    }
                    length -= 8;
                }
                output << endl;
            }
            output.close();
        }
    }
}