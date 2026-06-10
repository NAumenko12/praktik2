#include "input_file.h"

void decryptFile(){
    try{
        int p{};
        int g{};
        int publicKey{};
        int secretKey{};
        string inputPath;
        string outputPath;
        cout << "\nРасшифрование файла\n";
        cout << "Введите путь к файлу шифртекста: ";
        cin >> inputPath;
        cout << "Введите путь к файлу для результата: ";
        cin >> outputPath;
        cout << "Введите секретный ключ Cb: ";
        cin >> secretKey;
        ifstream in(inputPath, ios::binary);
        if (!in){
            throw "не удалось открыть файл шифртекста";
        }
        ofstream out(outputPath, ios::binary);
        if (!out){
            throw "не удалось создать файл результата";
        }
        in.read(reinterpret_cast<char*>(&p), sizeof(p));
        in.read(reinterpret_cast<char*>(&g), sizeof(g));
        in.read(reinterpret_cast<char*>(&publicKey), sizeof(publicKey));
        if (!in){
            throw "не удалось прочитать параметры из файла шифртекста";
        }
        cout << "\nПараметры из файла шифртекста\n";
        cout << "p = " << p << ", g = " << g << ", Db = " << publicKey << "\n";
        cout << "\nШаги расшифрования файла по Эль-Гамалю\n";
        int a{};
        int b{};
        int number = 0;
        while (in.read(reinterpret_cast<char*>(&a), sizeof(a)) &&
               in.read(reinterpret_cast<char*>(&b), sizeof(b))){
            cout << "\nПара " << number + 1 << ": (" << a << ", " << b << ")\n";
            PairCode pairCode{a, b};
            int m = decryptByte(pairCode, p, secretKey);
            out.put(static_cast<char>(m));
            cout << "Байт записан в файл результата.\n";
            ++number;
        }
        cout << "Файл расшифрован. Всего байт: " << number << "\n";
    }
    catch (const char* error){
        cout << "Ошибка: " << error << ".\n";
    }
}
