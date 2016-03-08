/**
 * Oberklasse von Decode und Encode
 * Enthält Methoden und Variablen, die für beide Schritte notwendig sind.
 * @author Sandro Käppner, Daniel Hänsler
 */


#ifndef HUFFMAN_CODE_H
#define HUFFMAN_CODE_H

#include <fstream>
#include <list>
#include "Tree.h"

class Code {
protected:
    string line = ""; // zum Speichern der eingelesenen Zeile
    list<Tree *> trees; // zum Speichern der Bäume
    char *inputfile; // Dateiname der Inputdatei
    char *outputfile; // Dateiname der Outputdatei
    ifstream input; // Inputstream
    ofstream output; // Outputstream

    void buildTree(); // Konstruiert den Baum aus den Buchstaben, sie im Text vorkommen.

public:
    virtual void doCode() = 0; // ist die allgemeine Methode, die alle Schritte zur Codierung ausführt.
};


#endif //HUFFMAN_CODE_H
