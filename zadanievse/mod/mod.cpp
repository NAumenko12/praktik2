#include "mod.h"

int mod(int base, int power, int modulo){
    try{
        if (power < 0){
            throw "степень должна быть неотрицательной";
        }
        if (!isPrime(modulo)){
            throw "модуль p не является простым";
        }
        int gcdResult = gcd(base, modulo);
        if (gcdResult != 1){
            throw "a и p не взаимно простые";
        }
        base %= modulo;
        if (base < 0){
            base += modulo;
        }
        power %= modulo - 1;
        int result = 1;
        for (int i = 0; i < power; ++i){
            result *= base;
            result %= modulo;
        }
        return result;
    }
    catch (const char* error){
        cout << "Ошибка: " << error << ".\n";
        return -1;
    }
}

int modFermat(int base, int power, int modulo){
    try{
        cout << "\nПервый способ: теорема Ферма\n";
        cout << "Вычисляем " << base << "^" << power << " mod " << modulo << "\n";
        cout << "Шаг 1. Проверяем степень.\n";
        if (power < 0){
            throw "степень должна быть неотрицательной";
        }
        cout << "Степень подходит: " << power << "\n";
        cout << "Шаг 2. Проверяем, что модуль простой.\n";
        if (!isPrime(modulo)){
            throw "модуль p не является простым";
        }
        cout << modulo << " - простое число.\n";
        cout << "Шаг 3. Проверяем взаимную простоту a и p.\n";
        int gcdResult = gcd(base, modulo);
        cout << "gcd(" << base << ", " << modulo << ") = " << gcdResult << "\n";
        if (gcdResult != 1){
            throw "a и p не взаимно простые";
        }
        cout << "Числа взаимно простые, теорему Ферма применять можно.\n";
        cout << "Шаг 4. Приводим основание по модулю.\n";
        int newBase = base % modulo;
        if (newBase < 0){
            newBase += modulo;
        }
        cout << base << " mod " << modulo << " = " << newBase << "\n";
        cout << "Шаг 5. Уменьшаем степень по модулю p - 1.\n";
        int newPower = power % (modulo - 1);
        cout << power << " mod " << modulo - 1 << " = " << newPower << "\n";
        cout << "Теперь считаем " << newBase << "^" << newPower << " mod " << modulo << "\n";
        cout << "Шаг 6. Считаем оставшуюся степень обычным циклом.\n";
        int result = 1;
        for (int i = 0; i < newPower; ++i){
            result *= newBase;
            result %= modulo;
            cout << "После умножения " << i + 1 << ": result = " << result << "\n";
        }
        cout << "Ответ через теорему Ферма: " << result << "\n";
        return result;
    }
    catch (const char* error){
        cout << "Ошибка: " << error << ".\n";
        cout << "Теорему Ферма применить нельзя.\n";
        return -1;
    }
}
