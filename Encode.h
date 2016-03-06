/**
 * @author Sandro Käppner, Daniel Hänsler
 */


#ifndef HUFFMAN_ENCODE_H
#define HUFFMAN_ENCODE_H
#define NMBR_CHARS 95

#include <string>
#include <fstream>
#include <list>
#include "Tree.h"
#include "Code.h"

using namespace std;

class Encode : public Code {
private:
    int totalchar = 0;
    int cntdiffchar = 0;
    int cntChar[NMBR_CHARS] = {0};
    int character = 0;

    void getCntChar();
    void buildLeaves();
    Tree *getCharTree(Tree *, char);
    list<bool> getCharCode(Tree *);
    list<bool> getCode();
    void writeCode();
    void writeTree();
    void writeFile();

public:
    Encode(char *, char *);
    void doCode();
};

#endif //HUFFMAN_ENCODE_H
