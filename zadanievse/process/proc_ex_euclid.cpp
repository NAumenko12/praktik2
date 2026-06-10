#include "proc_ex_euclid.h"

void procExEuclid(){
    try{
        int a{};
        int b{};
        int u{};
        int v{};
        cout << "\nЗадание 2. Расширенный алгоритм Евклида\n";
        cout << "Введите a: ";
        cin >> a;
        cout << "Введите b: ";
        cin >> b;
        if (b <= 1){
            throw "модуль b должен быть больше 1";
        }
        int gcdResult = exGcdSteps(a, b, u, v);
        if (gcdResult != 1){
            throw "gcd(a, b) не равен 1";
        }
        int d = u % b;
        if (d < 0){
            d += b;
        }
        cout << "u = " << u << ", v = " << v << "\n";
        cout << "d = " << d << "\n";
    }
    catch (const char* error){
        cout << "Ошибка: " << error << ".\n";
        cout << "d не существует.\n";
    }
}
