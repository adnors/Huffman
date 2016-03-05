#include "Encode.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc >= 2) { //Hiermit wird geprüft, ob die benötigten Parameter gesetzt sind (Dateiname, encode/decode)
        Encode encode(argv[1], argv[2]);
        encode.doEncode();
    }
    return 0;
}