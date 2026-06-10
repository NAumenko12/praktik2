#include "optional_func.h"

bool isPrime(int number){
    if (number < 2){
        return false;
    }
    if (number == 2){
        return true;
    }
    if (number % 2 == 0){
        return false;
    }
    for (int d = 3; d * d <= number; d += 2){
        if (number % d == 0) {
            return false;
        }
    }
    return true;
}

int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
