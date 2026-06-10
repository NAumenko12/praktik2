#ifndef CRYPTO_H
#define CRYPTO_H

#include <iostream>
#include <string>
#include <vector>

#include "../euclid/euclid.h"
#include "../mod/mod.h"

using namespace std;

struct PairCode{
    int a;
    int b;
};

int makePublicKey(int g, int secretKey, int p);
PairCode encryptByte(int m, int p, int g, int publicKey, int k);
int decryptByte(PairCode pairCode, int p, int secretKey);
vector<PairCode> encryptText(const string& text, int p, int g, int publicKey, int k);
string decryptText(const vector<PairCode>& cipher, int p, int secretKey);

#endif
