/**
 * @author Sandro Käppner, Daniel Hänsler
 */

#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Tree {
private:
    Tree *root; //Wurzel des Baums
    Tree *rTree; //Rechter Teilbaum
    Tree *lTree; //Linker Teilbaum
    int value; //Wert des Knotens
    char character; //Zeichen des Knotens

public:
    Tree(Tree *root, Tree *rightTree, Tree *leftTree, int v, char c); //Konstruktor mit Wurzel, Teilbäumen, Wert und Zeichen
    Tree *getRoot(); //Gibt die Wurzel zurück
    Tree *getRightTree(); //Gibt den rechten Teilbaum zurück
    Tree *getLeftTree(); //Gibt den linken Teilbaum zurück
    int getValue(); //Gibt den Wert des Knotens zurück
    char getCharacter(); //Gibt das Zeichen des Knotens zurück
    void setRoot(Tree *); //Definiert die Baumwurzel
    string toString(); //Ausgabe der Baumparamter als String

    bool isLeaf(); //True, wenn Knoten ein Blatt ist
};


#endif //HUFFMAN_TREE_H
