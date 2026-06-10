#include "input_file.h"

void encryptFile(){
    try{
        int p{};
        int g{};
        int secretKey{};
        int k{};
        string inputPath;
        string outputPath;
        cout << "\nШифрование файла\n";
        cout << "Для любых файлов удобно: p = 257, g = 3, Cb = 13, k = 7.\n";
        cout << "Введите p: ";
        cin >> p;
        cout << "Введите g: ";
        cin >> g;
        cout << "Введите секретный ключ Cb: ";
        cin >> secretKey;
        cout << "Введите случайное число k: ";
        cin >> k;
        cout << "Введите путь к исходному файлу: ";
        cin >> inputPath;
        cout << "Введите путь к файлу шифртекста: ";
        cin >> outputPath;
        if (p <= 255){
            throw "для шифрования байтов p должно быть больше 255";
        }
        ifstream in(inputPath, ios::binary);
        if (!in){
            throw "не удалось открыть исходный файл";
        }
        ofstream out(outputPath, ios::binary);
        if (!out){
            throw "не удалось создать файл шифртекста";
        }
        int publicKey = makePublicKey(g, secretKey, p);
        out.write(reinterpret_cast<char*>(&p),sizeof(p));
        out.write(reinterpret_cast<char*>(&g),sizeof(g));
        out.write(reinterpret_cast<char*>(&publicKey), sizeof(publicKey));
        cout << "\nШаги шифрования файла по Эль-Гамалю\n";
        cout << "В файл шифртекста записаны параметры: p = " << p << ", g = " << g << ", Db = " << publicKey << "\n";
        char ch{};
        int number = 0;
        while (in.get(ch)){
            int m = static_cast<unsigned char>(ch);
            int currentK = k + number;
            cout << "\nБайт " << number + 1 << "\n";
            PairCode pairCode = encryptByte(m, p, g, publicKey, currentK);
            out.write(reinterpret_cast<char*>(&pairCode.a), sizeof(pairCode.a));
            out.write(reinterpret_cast<char*>(&pairCode.b), sizeof(pairCode.b));
            cout << "В бинарный файл записана пара: " << pairCode.a << " " << pairCode.b << "\n";
            ++number;
        }
        cout << "Файл зашифрован. Всего байт: " << number << "\n";
    }
    catch (const char* error){
        cout << "Ошибка: " << error << ".\n";
    }
}
