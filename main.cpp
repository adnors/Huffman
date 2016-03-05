#include "Encode.h"
#include "Decode.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc >= 3) { //Hiermit wird geprüft, ob die benötigten Parameter gesetzt sind (Dateiname, encode/decode)
        switch (*argv[1]) {
            case 'e':
                Encode encode(argv[2], argv[3]);
                encode.doEncode();
                break;
            case 'd':
                Decode decode(argv[2], argv[3]);
                decode.doDecode();
                break;
            default:
                cout << "Falscher Eingabeparameter." << endl;
                cout << "\te: für Kompriemieren" << endl;
                cout << "\td: für Entpacken" << endl;
        }
    }
    return 0;
}