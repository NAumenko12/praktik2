#ifndef PROC_ELGAMAL_H
#define PROC_ELGAMAL_H
#include "../proc_console/input_console.h"
#include "../proc_file/input_file.h"
#include <iostream>

using namespace std;

enum class ElgamalChoice{
    EncryptConsole = 1,
    DecryptConsole = 2,
    EncryptFile = 3,
    DecryptFile = 4
};

void procElgamal();

#endif
