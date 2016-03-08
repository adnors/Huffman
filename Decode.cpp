/**
 * Klasse zum Entpacken der komprimierten Datei
 * @author Sandro Käppner, Daniel Hänsler
 */


#include "Decode.h"

/**
 * @brief Konstruktor, speichert die Dateinamen von Input und Output
 * @param i Pointer auf den Namen der Inputdatei
 * @param o Pointer auf den Namen der Outputdatei
 * @retrun Objekt der Klasse Decode
 */
Decode::Decode(char *i, char *o) {
    inputfile = i;
    outputfile = o;
}

/**
 * @brief führt alle Schritte zum Entpacken
 *
 * Zuerst wird der Baum aus der Datei gelesen, dann wird er mit der Methode von Code aufgebaut.
 * Im letzten Schritt wird der Text aus der Datei gelesen.
 */
void Decode::doCode() {
    input.open(inputfile);
    parseTree();
    buildTree();
    parseText();
    input.close();
}

/**
 * @brief Hilfsmethode zum parsen des Baums aus der Datei
 *
 * Solange man noch in der ersten Zeile ist, wird abwechselnd die Anzahl des Zeichens und das Zeichen eingelesen.
 * Dazwischen steht immer ein Leerzeichen. Am Ende wird noch das Enter gelesen.
 */
void Decode::parseTree() {
    if (input.is_open()) {
        char c;
        int v;
        while (input.peek() != '\n') { // Solange man noch in der ersten Zeile ist:
            input >> v; // Anzahl einlesen
            input.read(&c, sizeof(char)); // Lese Leerzeichen
            input.read(&c, sizeof(char)); // Buchstabe einlesen
            trees.push_back(new Tree(nullptr, nullptr, nullptr, v, c)); // Knoten erstellen und in die Liste schreiben
            input.read(&c, sizeof(char)); // Lese Leerzeichen
        }
        trees.sort([](Tree *first, Tree *second) { return first->getValue() < second->getValue(); }); // Liste sortieren
        input.read(&c, 1); // Lese \n
    }
}

/**
 * @brief Hilfsmethode zum parsen des Texts
 *
 * Wenn die Dateien offen sind, wird die Inputdatei zeilenweise durchgegangen und jedes Zeichen bitweise gelesen.
 */
void Decode::parseText() {
    if (input.is_open()) {
        output.open(outputfile);
        if (output.is_open()) {
            while (!input.eof()) { // Solange die Datei nicht leer ist:
                Tree *tree = trees.front(); // Die Wurzel auswählen
                int length;
                input >> length; // Länge der Zeile lesen
                getline(input, line); // Lese \n
                getline(input, line); // Zeile lesen
                for (int i = 0; i < line.length(); i++) { // Zeile bearbeiten
                    char c = line[i];
                    for (int j = 0; j < 8 && j < length; j++) { // Die einzelnen Bits lesen
                        bool right = (bool) ((c >> (7 - j)) & 1);
                        tree = right ? tree->getRightTree()
                                     : tree->getLeftTree(); // 0-->linker Teilbaum; 1-->rechter Teilbaum
                        if (tree->isLeaf()) { // Wenn das Ende erreicht ist, den gefundenen Buchstaben schreiben
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