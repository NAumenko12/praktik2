#include "proc_elgamal.h"

void procElgamal(){
    int choiceNumber{};
    cout << "\nЗадание 4. Эль-Гамаль\n";
    cout << "1 - зашифровать текст из консоли\n";
    cout << "2 - расшифровать пары из консоли\n";
    cout << "3 - зашифровать файл\n";
    cout << "4 - расшифровать файл\n";
    cout << "Выбор: ";
    cin >> choiceNumber;
    ElgamalChoice choice = static_cast<ElgamalChoice>(choiceNumber);
    switch (choice){
        case ElgamalChoice::EncryptConsole:
            encryptConsole();
            break;
        case ElgamalChoice::DecryptConsole:
            decryptConsole();
            break;
        case ElgamalChoice::EncryptFile:
            encryptFile();
            break;
        case ElgamalChoice::DecryptFile:
            decryptFile();
            break;
        default:
            cout << "Такого пункта нет.\n";
            break;
    }
}
