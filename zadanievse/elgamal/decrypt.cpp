#include "crypto.h"

int decryptByte(PairCode pairCode, int p, int secretKey) {
    int a = pairCode.a;
    int b = pairCode.b;
    cout << "Считаем temp = a^Cb mod p\n";
    int temp = mod(a, secretKey, p);
    cout << "temp = " << temp << "\n";
    cout << "Находим обратное число к temp по модулю p\n";
    int inverse = exGcdC(temp, p);
    inverse %= p;
    if (inverse < 0){
        inverse += p;
    }
    cout << "inverse = " << inverse << "\n";
    cout << "Восстанавливаем m = b * inverse mod p\n";
    int m = (b * inverse) % p;
    cout << "m = " << b << " * " << inverse << " mod " << p << " = " << m << "\n";
    return m;
}

string decryptText(const vector<PairCode>& cipher, int p, int secretKey) {
    string text;
    cout << "\nШаги расшифрования по Эль-Гамалю\n";
    cout << "Используем p = " << p << ", Cb = " << secretKey << "\n";
    for (size_t i = 0; i < cipher.size(); ++i) {
        cout << "\nПара " << i + 1 << ": (" << cipher[i].a << ", " << cipher[i].b << ")\n";
        int m = decryptByte(cipher[i], p, secretKey);
        text += static_cast<char>(m);
        cout << "Полученный символ добавлен в текст.\n";
    }
    return text;
}
