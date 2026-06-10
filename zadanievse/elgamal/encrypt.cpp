#include "crypto.h"

int makePublicKey(int g, int secretKey, int p) {
    cout << "\nШаг создания открытого ключа\n";
    cout << "Секретный ключ Cb = " << secretKey << "\n";
    cout << "Открытый ключ Db = g^Cb mod p\n";
    int publicKey = mod(g, secretKey, p);
    cout << "Db = " << publicKey << "\n";
    return publicKey;
}

PairCode encryptByte(int m, int p, int g, int publicKey, int k) {
    cout << "m = " << m << "\n";
    cout << "k = " << k << "\n";
    cout << "Считаем a = g^k mod p\n";
    int a = mod(g, k, p);
    cout << "a = " << a << "\n";
    cout << "Считаем Db^k mod p\n";
    int dbPower = mod(publicKey, k, p);
    cout << "Db^k mod p = " << dbPower << "\n";
    cout << "Считаем b = m * Db^k mod p\n";
    int b = (m * dbPower) % p;
    cout << "b = " << m << " * " << dbPower << " mod " << p << " = " << b << "\n";
    cout << "Полученная пара: (" << a << ", " << b << ")\n";
    return PairCode{a, b};
}

vector<PairCode> encryptText(const string& text, int p, int g, int publicKey, int k) {
    vector<PairCode> cipher;
    cout << "\nШаги шифрования по Эль-Гамалю\n";
    cout << "Используем p = " << p << ", g = " << g << ", Db = " << publicKey << "\n";
    for (size_t i = 0; i < text.size(); ++i) {
        int m = static_cast<unsigned char>(text[i]);
        int currentK = k + i;
        cout << "\nСимвол " << i + 1 << "\n";
        PairCode pairCode = encryptByte(m, p, g, publicKey, currentK);
        cipher.push_back(pairCode);
    }
    return cipher;
}
