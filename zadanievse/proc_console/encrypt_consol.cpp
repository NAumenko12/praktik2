#include "input_console.h"

void encryptConsole(){
    try{
        int p{};
        int g{};
        int secretKey{};
        int k{};
        string text;
        cout << "\nШифрование текста из консоли\n";
        cout << "удобно: p = 257, g = 3, Cb = 13, k = 7.\n";
        cout << "Введите p: ";
        cin >> p;
        cout << "Введите g: ";
        cin >> g;
        cout << "Введите секретный ключ Cb: ";
        cin >> secretKey;
        cout << "Введите случайное число k: ";
        cin >> k;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Введите исходный текст: ";
        getline(cin, text);
        if (p <= 255){
            throw "для текста p должно быть больше 255";
        }
        int publicKey = makePublicKey(g, secretKey, p);
        vector<PairCode> cipher = encryptText(text, p, g, publicKey, k);
        cout << "\nШифртекст. Эти пары можно ввести при расшифровании:\n";
        for (size_t i = 0; i < cipher.size(); ++i){
            cout << cipher[i].a << " " << cipher[i].b << "\n";
        }
    }
    catch (const char* error){
        cout << "Ошибка: " << error << ".\n";
    }
}
