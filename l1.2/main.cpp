#include <iostream>
#include <locale>
#include <codecvt>
#include <string>

using namespace std;

// Класс для шифрования и дешифрования
class modKey {
public:
    modKey(int key) : key(key % 256) {} // Ограничение ключа по 256 для расширения данных

    wstring encrypt(const wstring& text) {
        wstring result = text;
        for (auto& c : result) {
            c = static_cast<wchar_t>((static_cast<int>(c) + key) % 256);
        }
        return result;
    }

    wstring decrypt(const wstring& text) {
        wstring result = text;
        for (auto& c : result) {
            c = static_cast<wchar_t>((static_cast<int>(c) - key + 256) % 256);
        }
        return result;
    }

private:
    int key;
};

int main() {
    // Установка локали для поддержки русских символов
    locale loc("ru_RU.UTF-8");
    locale::global(loc);

    int key;
    wstring text;
    int op;

    // Запрос ключа шифрования
    wcout << L"Шифратор готов. Введите ключ (целое число): ";
    wcin >> key;

    // Проверка, был ли введен корректный ключ
    if (!wcin.good()) {
        wcerr << L"Ключ неверен.\n";
        return 1; // Ошибка при вводе ключа
    }

    modKey cipher(key);

    do {
        // Запрос операции (шифрование, расшифровка или выход)
        wcout << L"Шифратор готов. Введите операцию (0-выход, 1-шифровать, 2-дешифровать): ";
        wcin >> op;

        if (op > 2 || op < 0) {
            wcout << L"Недопустимая операция\n";
        } else if (op > 0) {
            // Запрос текста для обработки
            wcout << L"Шифратор готов. Введите текст: ";
            wcin.ignore(); // Очистка буфера ввода
            getline(wcin, text); // Чтение строки с пробелами
            
            if (op == 1) {
                wcout << L"Зашифрованный текст: " << cipher.encrypt(text) << endl;
            } else {
                wcout << L"Расшифрованный текст: " << cipher.decrypt(text) << endl;
            }
        }
    } while (op != 0);

    return 0; // Успешное завершение программы
}
