#ifndef EUCLID_H
#define EUCLID_H

#include <iostream>

using namespace std;

int exGcd(int a, int b, int &u, int &v);
int exGcdSteps(int a, int b, int &u, int &v);
int exGcdC(int base, int module);
int exGcdCSteps(int base, int module);

#endif
