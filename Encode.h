/**
 *
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
    int totalchar = 0; //Gesamtanzahl der Zeichen in der Eingabedatei
    int cntdiffchar = 0; //Anzahl der verschiedenen Zeichen in der Eingabedatei
    int cntChar[NMBR_CHARS] = {0}; //Array, in dem die Häufigkeiten der Buchstaben gespeichert werden
    int character = 0; 

    void getCntChar(); //gibt die Anzahl gelesener Zeichen zurück
    void buildLeaves(); //erzeugt ein Blatt für einen Buchstaben
    Tree *getCharTree(Tree *, char); //Liefert den Knoten eines Baumes zurück, der den übergebenen Buchstaben enthält
    list<bool> getCharCode(Tree *); //Liefert die Bitkodierung als Liste zurück
    list<bool> getCode();
    void writeCode(); //Schreibt den Code in die Datei
    void writeTree(); //Erzeugt den Baum
    void writeFile(); //Schreibt die Komprimierungsdatei

public:
    Encode(char *, char *); // Konstruktor
    void doCode(); //Startet die Komprimierung
};

#endif //HUFFMAN_ENCODE_H
