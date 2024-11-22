#ifndef MODKEY_H
#define MODKEY_H

#include <string>

class modKey {
private:
    int key; // Поле для хранения ключа

public:
    // Конструктор
    modKey(int key);
    
    // Метод для шифрования текста
    std::wstring encrypt(const std::wstring& text);
    
    // Метод для расшифрования текста
    std::wstring decrypt(const std::wstring& text);
};

#endif // MODKEY_H
