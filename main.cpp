#include <fstream>
#include "Encode.h"

using namespace std;

int main(int argc, char *argv[]) {

    ifstream f;
    if (argc >= 2) {
        f.open(argv[1], ios::in);
        Encode encode = Encode(&f);
        encode.doEncode();
    }
    f.close();
    return 0;
}