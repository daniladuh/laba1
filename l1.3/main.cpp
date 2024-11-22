#include "modAlphakey.h"

using namespace std;

int main() {
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    int key;
    wstring text;
    int op;
    
    wcout << L"Cipher ready. Input key: ";
    wcin >> key;
    
    if (!wcin.good()) {
        wcerr << L"key not valid\n";
        return 0;
    }
    
    modAlphakey cipher(key);
    
    do {
        wcout << L"Cipher ready. Input operation (0-exit, 1-encrypt, 2-decrypt): ";
        wcin >> op;

        if (op > 2) {
            wcout << L"Illegal operation\n";
        } else if (op > 0) {
            wcout << L"Cipher ready. Input text: ";
            wcin.ignore(); // Очистка из буфера перед getline
            getline(wcin, text); // Используем getline для работы со всеми символами

            if (text.empty()) {
                wcout << L"Operation aborted: invalid text\n";
            } else {
                if (op == 1) {
                    wcout << L"Encrypted text: " << cipher.encrypt(text) << endl;
                } else {
                    wcout << L"Decrypted text: " << cipher.decrypt(text) << endl;
                }
            }
        }
    } while (op != 0);
    
    return 0;
}
