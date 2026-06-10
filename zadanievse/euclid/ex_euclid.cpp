#include "euclid.h"
#include <iomanip>
#include <vector>

int exGcd(int a, int b, int &u, int &v){
    int u1 = 1, v1 = 0;
    int u2 = 0, v2 = 1;
    while (b != 0){
        int q = a / b;
        int r = a % b;
        int nextU = u1 - q * u2;
        int nextV = v1 - q * v2;
        a = b;
        b = r;
        int newU = u2;
        int newV = v2;
        u2 = nextU;
        v2 = nextV;
        u1 = newU;
        v1 = newV;
    }
    u = u1;
    v = v1;
    return a;
}

int exGcdSteps(int a, int b, int &u, int &v){
    vector<int> tableR;
    vector<int> tableQ;
    vector<int> tableU;
    vector<int> tableV;
    int r0 = b;
    int r1 = a;
    int u0 = 0;
    int v0 = 1;
    int u1 = 1;
    int v1 = 0;
    tableR.push_back(r0);
    tableQ.push_back(0);
    tableU.push_back(u0);
    tableV.push_back(v0);
    tableR.push_back(r1);
    tableQ.push_back(0);
    tableU.push_back(u1);
    tableV.push_back(v1);
    cout << "\nШаги расширенного алгоритма Евклида\n";
    cout << "Ищем u и v для " << a << " * u + " << b << " * v = gcd(" << a << ", " << b << ")\n";
    cout << "Начальные значения:\n";
    cout << "r0 = " << r0 << ", u0 = " << u0 << ", v0 = " << v0 << "\n";
    cout << "r1 = " << r1 << ", u1 = " << u1 << ", v1 = " << v1 << "\n";
    int step = 1;
    while (r1 != 0){
        int q = r0 / r1;
        int r = r0 - q * r1;
        int nextU = u0 - q * u1;
        int nextV = v0 - q * v1;
        cout << "\nИтерация " << step << "\n";
        cout << "q = " << r0 << " / " << r1 << " = " << q << "\n";
        cout << "r = " << r0 << " - " << q << " * " << r1 << " = " << r << "\n";
        cout << "u = " << u0 << " - " << q << " * " << u1 << " = " << nextU << "\n";
        cout << "v = " << v0 << " - " << q << " * " << v1 << " = " << nextV << "\n";
        tableR.push_back(r);
        tableQ.push_back(q);
        tableU.push_back(nextU);
        tableV.push_back(nextV);
        r0 = r1;
        r1 = r;
        u0 = u1;
        u1 = nextU;
        v0 = v1;
        v1 = nextV;
        ++step;
    }
    u = u0;
    v = v0;
    cout << "\nТаблица r q u v\n";
    cout << setw(8) << "r" << setw(8) << "q" << setw(8) << "u" << setw(8) << "v" << "\n";
    for (size_t i = 0; i < tableR.size(); ++i){
        cout << setw(8) << tableR[i];
        if (i < 2){
            cout << setw(8) << "-";
        } else {
            cout << setw(8) << tableQ[i];
        }
        cout << setw(8) << tableU[i] << setw(8) << tableV[i] << "\n";
    }
    cout << "\nПоследний ненулевой остаток: " << r0 << "\n";
    cout << "Получили: " << a << " * " << u << " + " << b << " * " << v << " = " << r0 << "\n";
    return r0;
}
