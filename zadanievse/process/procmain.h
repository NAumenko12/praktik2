#ifndef PROCMAIN_H
#define PROCMAIN_H

#include "procmod.h"
#include "procdvoich.h"
#include "proc_ex_euclid.h"
#include "proc_ex_euclidC.h"
#include "proc_elgamal.h"
#include <iostream>

using namespace std;

enum class MainChoice{
    Exit,
    ModAndBinary,
    ExtendedEuclid,
    InverseNumber,
    Elgamal,
    Unknown
};

void procMain();

#endif
