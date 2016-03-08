/**
 * Diese Klasse komprimiert die Datei an der Stelle input und gibt die neue Datei an der Stelle ouput aus.
 * Zum komprimieren muss die Methode doCode() gestartet werden.
 * @author Sandro Käppner, Daniel Hänsler
 */


#include "Encode.h"

using namespace std;

/**
 * @brief Diese Methode speichert Ein- und Ausgabedatei.
 * @param
 * @return Encode
 *
 */
Encode::Encode(char *i, char *o) {
    inputfile = i;
    outputfile = o;
}

/**
 * @brief Diese Methode enkodiert die Datei.
 * @param
 * @return void
 * Die Encode-Methode zählt die Zeichen der Eingabedatei, erstellt die entsprechenden Knoten und schließlich den fertigen Baum
 */
void Encode::doCode() {
    getCntChar();
    buildLeaves();
    buildTree();
    writeFile();
}

/**
 * @brief Zählt die Zeichen der Eingabedatei
 * @return void
 *
 * Es wird die Inputdatei zeilenweise durchgegangen und jedes Zeichen gezählt. Das Ergebnis wird in das Array cntChar
 * geschrieben.
 */
void Encode::getCntChar() {
    input.open(inputfile);
    if (input.is_open()) {
        char character;
        while (!input.eof()) {
            getline(input, line); // lese Zeile
            for (unsigned int i = 0; i < line.length(); i++) {
                character = (int) line[i]; // lese ASCII-Wert des Buchstabens
                if (cntChar[character - 32] == 0) {
                    cntdiffchar++;
                }
                cntChar[character - 32]++;
                totalchar++;
            }
        }
        input.close();
    }
}

/**
 * @brief Erzeugt die Blätter des Baums
 * @return void
 *
 * Für jedes Zeichen im Array cntChar wird ein Knoten in der Liste angelegt. Die liste wird am Ende sortiert.
 */
void Encode::buildLeaves() {
    for (int i = 0; i < NMBR_CHARS; i++) {
        if (cntChar[i] != 0) { // nicht gelesene zeichen filtern
            Tree *newTree = new Tree(nullptr, nullptr, nullptr, cntChar[i], (char) (i + 32));
            trees.push_back(newTree);
        }
    }
    trees.sort([](Tree *first, Tree *second) { return first->getValue() < second->getValue(); }); // Liste sortiernen
}

/**
 * @brief Liefert den Knoten zurück, der den übergebenen Buchstaben enthält.
 * @param root Wurzel des Baums, der durchsucht werden soll
 * @param c Buchstabe, der gesucht wird
 * @return Knoten, der den Buchstaben enthält
 *
 * Es wird rekursiv nach dem Buchstaben gesucht. Erst wird der linke und dann der rechte Teilbaum durchsucht.
 */
Tree *Encode::getCharTree(Tree *root, char c) {
    Tree *charTree;
    if (root->isLeaf() && root->getCharacter() == c) { // Wenn der Buchstabe gefunden wurde, speichern.
        charTree = root;
    } else {
        if (root->isLeaf() &&
            root->getCharacter() != c) { // Wenn man im falschen Teilbaum ist, wird nullptr zurückgegeben
            charTree = nullptr;
        } else {
            charTree = getCharTree(root->getLeftTree(), c); // linken Teilbaum durchsuchen
            if (charTree == nullptr) { // falls linker Teilbaum falsch war, rechten Teilbaum durchsuchen
                charTree = getCharTree(root->getRightTree(), c);
            }
        }
    }
    return charTree;
}

/**
 * @brief Liefert den Bitcode für einen Baum zurück
 * @param tree Baum, für den der Code gesucht wird
 * @return Liste mit bool Werten für 1 und 0
 *
 * Es wird der Vaterknoten des Knotens aufgerufen und geprüft, ob der Knoten linker oder rechter Teilbaum ist.
 * Die Methode funktioniert rekursiv.
 */
list<bool> Encode::getCharCode(Tree *tree) {
    list<bool> code;
    Tree *root = tree->getRoot(); // Vaterknoten speichern
    if (root->getRoot() != nullptr) { // Wenn es keinen nächsten Vaterknoten gibt, ist die Wurzel erreicht
        code = getCharCode(root);
        code.push_back(root->getLeftTree() != tree); // linker Teilbaum -> 0 ; rechter Teilbaum -> 1
    } else {
        code.push_back(root->getLeftTree() != tree); // linker Teilbaum -> 0 ; rechter Teilbaum -> 1
    }
    return code;
}

/**
 * @brief Liefert den Bitcode für eine Zeile zurück
 * @return Liste mit bool Werten, für 1 und 0
 *
 * Es wird die Zeile Buchstabe für Buchstabe durchgegangen und für jeden Buchstaben die Methode getCharCode aufgerufen.
 */
list<bool> Encode::getCode() {
    string line;
    list<bool> code;
    if (input.is_open()) {
        getline(input, line);
        for (unsigned int i = 0; i < line.length(); i++) { // Zeile durchgehen
            code.splice(code.end(),
                        getCharCode(getCharTree(trees.front(), line[i]))); // Code am Ende der Liste anhängen
        }
    }
    return code;
}

/**
 * @brief Schreibt den Bitcode in die Datei.
 *
 * Geht die Inputdatei zeilenweise durch und schreibt den für jede Zeile gefundenen Code in die Datei.
 */
void Encode::writeCode() {
    input.open(inputfile);
    if (output.is_open() && input.is_open()) {
        while (!input.eof()) {
            list<bool> code = getCode(); // Bitcode für Zeile speichern
            string out = "";
            int outLength = 0; // Anzahl der Bits in der Zeile
            bool itNotEnd = true; // Iterator am Ende der Liste, Abbruchbedingung für die Schleife
            for (list<bool>::iterator it = code.begin(); itNotEnd;) {
                char c = 0;
                for (int i = 0; i < 8; i++, it++) { // 8 bits in ein char schreiben
                    c <<= 1;
                    if (it == code.end()) { // Ende der Liste erreicht
                        itNotEnd = false;
                    }
                    if (itNotEnd) {
                        c |= *it;
                        outLength++;
                    }
                }
                out += c;
            }
            output << outLength << '\n' << out << '\n';
        }
    }
}

/**
 * @brief Schreibt den Baum in die Datei
 *
 * Geht das Array cntChar durch und schreibt Anzahl des Buchstabens und den Buchstaben in die Datei.
 * Dazwischen stehen Leerzeichen.
 */
void Encode::writeTree() {
    for (int i = 0; i < NMBR_CHARS; i++) {
        if (cntChar[i] != 0) { // nicht gelesene Zeichen filtern
            output << cntChar[i] << " " << (char) (i + 32) << " ";
        }
    }
    output << '\n';
}

/**
 * @brief Schreibt die Ausgabedatei
 *
 * Schreibt erst den Baum und dann den Text.
 */
void Encode::writeFile() {
    output.open(outputfile, ios::binary);
    writeTree();
    writeCode();
    output.close();
}