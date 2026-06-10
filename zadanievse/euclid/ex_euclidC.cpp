#include "euclid.h"
#include <iomanip>
#include <vector>


int exGcdC(int base, int module){
    int r0 = module;
    int r1 = base;
    int u0 = 0;
    int u1 = 1;
    while (r1 != 0){
        int q = r0 / r1;
        int nextR = r0 - q * r1;
        int nextU = u0 - q * u1;
        r0 = r1;
        r1 = nextR;
        u0 = u1;
        u1 = nextU;
    }
    return u0;
}

int exGcdCSteps(int base, int module){
    vector<int> tableR;
    vector<int> tableQ;
    vector<int> tableU;
    int r0 = module;
    int r1 = base;
    int u0 = 0;
    int u1 = 1;
    tableR.push_back(r0);
    tableQ.push_back(0);
    tableU.push_back(u0);
    tableR.push_back(r1);
    tableQ.push_back(0);
    tableU.push_back(u1);
    cout << "\nШаги нахождения обратного числа\n";
    cout << "Ищем " << base << "^(-1) mod " << module << "\n";
    cout << "Начальные значения:\n";
    cout << "r0 = " << r0 << ", u0 = " << u0 << "\n";
    cout << "r1 = " << r1 << ", u1 = " << u1 << "\n";
    int step = 1;
    while (r1 != 0){
        int q = r0 / r1;
        int r = r0 - q * r1;
        int nextU = u0 - q * u1;
        cout << "\nИтерация " << step << "\n";
        cout << "q = " << r0 << " / " << r1 << " = " << q << "\n";
        cout << "r = " << r0 << " - " << q << " * " << r1 << " = " << r << "\n";
        cout << "u = " << u0 << " - " << q << " * " << u1 << " = " << nextU << "\n";
        tableR.push_back(r);
        tableQ.push_back(q);
        tableU.push_back(nextU);
        r0 = r1;
        r1 = r;
        u0 = u1;
        u1 = nextU;
        ++step;
    }
    cout << "\nТаблица r q u\n";
    cout << setw(8) << "r" << setw(8) << "q" << setw(8) << "u" << "\n";
    for (size_t i = 0; i < tableR.size(); ++i){
        cout << setw(8) << tableR[i];
        if (i < 2){
            cout << setw(8) << "-";
        } else {
            cout << setw(8) << tableQ[i];
        }
        cout << setw(8) << tableU[i] << "\n";
    }
    cout << "\nПоследний ненулевой остаток: " << r0 << "\n";
    cout << "Коэффициент u = " << u0 << "\n";
    cout << "Это число приводим по модулю " << module << ", чтобы получить положительный ответ.\n";
    int d = u0 % module;
    if (d < 0){
        d += module;
    }
    cout << "d = " << u0 << " mod " << module << " = " << d << "\n";
    return d;
}
