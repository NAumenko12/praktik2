#include "proc_ex_euclidC.h"


void procExEuclidC(){
    try{
        int number{};
        int modulo{};
        int u{};
        int v{};
        cout << "\nЗадание 3. Взаимно обратное число\n";
        cout << "Введите число: ";
        cin >> number;
        cout << "Введите модуль: ";
        cin >> modulo;
        if (modulo <= 1){
            throw "модуль m должен быть больше 1";
        }
        int gcdResult = exGcd(number, modulo, u, v);
        if (gcdResult != 1){
            throw "число и модуль не взаимно простые";
        }
        int d = exGcdCSteps(number, modulo);
        cout << number << "^(-1) mod " << modulo << " = " << d << "\n";
    }
    catch (const char* error){
        cout << "Ошибка: " << error << ".\n";
        cout << "Обратного числа не существует.\n";
    }
}
