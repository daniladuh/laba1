#include "modKey.h"

// Конструктор
modKey::modKey(int k) : key(k) {
    // Инициализация с ключом
}

// Реализация метода шифрования
std::wstring modKey::encrypt(const std::wstring& text) {
    std::wstring encrypted_text = text; // Здесь можно добавить логику шифрования
    // Пример: просто сдвинем символы на значение ключа
    for (auto& ch : encrypted_text) {
        ch += key; // Сдвигаем символы
    }
    return encrypted_text; // Возврат зашифрованного текста
}

// Реализация метода расшифрования
std::wstring modKey::decrypt(const std::wstring& text) {
    std::wstring decrypted_text = text; // Здесь можно добавить логику расшифрования
    // Пример: просто сдвинем символы обратно на значение ключа
    for (auto& ch : decrypted_text) {
        ch -= key; // Сдвигаем символы обратно
    }
    return decrypted_text; // Возврат расшифрованного текста
}
