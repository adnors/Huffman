#include <fstream>
#include "Encode.h"

using namespace std;

int main(int argc, char *argv[]) {

    ifstream f;
    if (argc >= 2) { //Hiermit wird geprüft, ob die benötigten Parameter gesetzt sind (Dateiname, encode/decode)
        Encode encode(argv[1], argv[2]);
        encode.doEncode();
    }
    f.close();
    return 0;
}