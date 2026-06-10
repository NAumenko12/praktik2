#include "procdvoich.h"

void procDvoich(int base, int power, int modulo, int resultFermat){
    int resultBinary = modBinary(base, power, modulo);
    cout << "\nИтог\n";
    if (resultFermat != -1){
        cout << "Через теорему Ферма: " << resultFermat << "\n";
    } else {
        cout << "Через теорему Ферма: нельзя посчитать для этих данных.\n";
    }
    if (resultBinary != -1){
        cout << "Через двоичный алгоритм: " << resultBinary << "\n";
    } else {
        cout << "Через двоичный алгоритм: нельзя посчитать для этих данных.\n";
    }
}
