/**
 * Klasse zum Entpacken der komprimierenten Datei
 * @author Sandro Käppner, Daniel Hänsler
 */


#ifndef HUFFMAN_DECODE_H
#define HUFFMAN_DECODE_H

#include "Code.h"

using namespace std;

class Decode : public Code {
private:
    void parseTree(); // Hilfsmethode zum parsen des Baums
    void parseText(); // Hilfsmethode zum parsen des Texts

public:
    Decode(char *, char *); // Konstruktor mit Dateinamen
    void doCode(); // führt alle Schritte zum Entpacken der Datei aus
};


#endif //HUFFMAN_DECODE_H
