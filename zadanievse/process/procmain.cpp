#include "procmain.h"

MainChoice getMainChoice(int choiceNumber){
    if (choiceNumber == 1){
        return MainChoice::ModAndBinary;
    }
    if (choiceNumber == 2){
        return MainChoice::ExtendedEuclid;
    }
    if (choiceNumber == 3){
        return MainChoice::InverseNumber;
    }
    if (choiceNumber == 4){
        return MainChoice::Elgamal;
    }
    if (choiceNumber == 0){
        return MainChoice::Exit;
    }
    return MainChoice::Unknown;
}

void procMain(){
    int choiceNumber{};
    cout << "1 - Ферма, Двоичное возведение в степень  \n";
    cout << "2 - Расширенный Алгоритм Евклида\n";
    cout << "3 - Вычисление взаимно обратного числа по модулю\n";
    cout << "4 - Шифр Эль-Гамаля\n";
    cout << "0 - выход\n";
    cout << "Выбор: ";
    cin >> choiceNumber;
    MainChoice choice = getMainChoice(choiceNumber);
    switch (choice){
        case MainChoice::ModAndBinary:{
            int base{};
            int power{};
            int modulo{};
            int resultFermat{};
            procMod(base, power, modulo, resultFermat);
            procDvoich(base, power, modulo, resultFermat);
            break;
        }
        case MainChoice::ExtendedEuclid:
            procExEuclid();
            break;
        case MainChoice::InverseNumber:
            procExEuclidC();
            break;
        case MainChoice::Elgamal:
            procElgamal();
            break;
        case MainChoice::Exit:
            cout << "Выход.\n";
            break;
        case MainChoice::Unknown:
        default:
            cout << "Такого задания нет.\n";
            break;
    }
}
