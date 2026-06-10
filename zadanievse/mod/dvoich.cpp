#include "dvoich.h"

int modBinary(int base, int power, int modulo){
    try{
        cout << "\nВторой способ: двоичное разложение степени\n";
        cout << "Вычисляем " << base << "^" << power << " mod " << modulo << "\n";
        cout << "Шаг 1. Проверяем модуль и степень.\n";
        if (modulo <= 1){
            throw "модуль должен быть больше 1";
        }
        if (!isPrime(modulo)){
            throw "модуль p не является простым";
        }
        if (power < 0){
            throw "степень должна быть неотрицательной";
        }
        cout << "Модуль и степень подходят.\n";
        cout << "Шаг 2. Приводим основание по модулю.\n";
        int oldBase = base;
        base %= modulo;
        if (base < 0){
            base += modulo;
        }
        cout << oldBase << " mod " << modulo << " = " << base << "\n";
        cout << "Шаг 3. Начальные значения.\n";
        int result = 1;
        int currentPower = power;
        int currentBase = base;
        cout << "result = " << result << "\n";
        cout << "currentBase = " << currentBase << "\n";
        cout << "currentPower = " << currentPower << "\n";
        cout << "Шаг 4. Выполняем двоичный алгоритм.\n";
        int step = 1;
        while (currentPower > 0){
            cout << "Итерация " << step << ": степень = " << currentPower << ", основание = " << currentBase << ", результат = " << result << "\n";
            if (currentPower % 2 == 1){
                result = (result * currentBase) % modulo;
                cout << "Степень нечетная, умножаем результат: result = " << result << "\n";
            } else {
                cout << "Степень четная, результат не меняется.\n";
            }
            currentBase = (currentBase * currentBase) % modulo;
            cout << "Возводим основание в квадрат: currentBase = " << currentBase << "\n";
            currentPower /= 2;
            cout << "Делим степень на 2: currentPower = " << currentPower << "\n";
            ++step;
        }
        cout << "Ответ через двоичный алгоритм: " << result << "\n";
        return result;
    }
    catch (const char* error){
        cout << "Ошибка: " << error << ".\n";
        cout << "Двоичный алгоритм применить нельзя.\n";
        return -1;
    }
}
