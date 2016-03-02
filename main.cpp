#include <fstream>
#include "Encode.h"

using namespace std;

int main(int argc, char *argv[]) {

    ifstream f;
    if (argc >= 2) { //Hiermit wird geprüft, ob die benötigten Parameter gesetzt sind (Dateiname, encode/decode)
        f.open(argv[1], ios::in);
        Encode encode = Encode(&f);
        encode.doEncode();
    }
    f.close();
    return 0;
}