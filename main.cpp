/**
 * @author Sandro Käppner, Daniel Hänsler
 */

#include "Encode.h"
#include "Decode.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc >= 3) { //Hiermit wird geprüft, ob die benötigten Parameter gesetzt sind (Dateiname, encode/decode)
        Code *code;
        switch (*argv[1]) {
            case 'e':
                code = new Encode(argv[2], argv[3]);
                code->doCode();
                delete (code);
                break;
            case 'd':
                code = new Decode(argv[2], argv[3]);
                code->doCode();
                delete (code);
                break;
            default:
                cout << "Falscher Eingabeparameter." << endl;
                cout << "\te: für Kompriemieren" << endl;
                cout << "\td: für Entpacken" << endl;
        }
    }
    return 0;
}