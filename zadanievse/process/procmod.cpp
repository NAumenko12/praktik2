#include "procmod.h"

void procMod(int& base, int& power, int& modulo, int& resultFermat){
    cout << "Задание 1. Вычисление a^x mod p\n";
    cout << "Введите base: ";
    cin >> base;
    cout << "Введите power: ";
    cin >> power;
    cout << "Введите modulo: ";
    cin >> modulo;
    resultFermat = modFermat(base, power, modulo);
}
