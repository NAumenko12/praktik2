#include "input_console.h"

void decryptConsole(){
    int p{};
    int secretKey{};
    int count{};
    vector<PairCode> cipher;
    cout << "\nРасшифрование пар из консоли\n";
    cout << "Введите p: ";
    cin >> p;
    cout << "Введите секретный ключ Cb: ";
    cin >> secretKey;
    cout << "Введите количество пар: ";
    cin >> count;
    cout << "Введите пары a b:\n";
    for (int i = 0; i < count; ++i){
        PairCode pairCode{};
        cin >> pairCode.a >> pairCode.b;
        cipher.push_back(pairCode);
    }

    string text = decryptText(cipher, p, secretKey);
    cout << "\nРасшифрованный текст:\n";
    cout << text << "\n";
}