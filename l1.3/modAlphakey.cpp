#include "modAlphakey.h"

modAlphakey::modAlphakey(int key) : key(key) {}

wstring modAlphakey::encrypt(const wstring& text) {
    wstring encryptedText;

    for (wchar_t c : text) {
        encryptedText += shiftChar(c, key);
    }
    return encryptedText;
}

wstring modAlphakey::decrypt(const wstring& text) {
    wstring decryptedText;

    for (wchar_t c : text) {
        decryptedText += shiftChar(c, -key);
    }
    return decryptedText;
}

wchar_t modAlphakey::shiftChar(wchar_t c, int key) {
    // Применение шифрования к символу
    return c + key;
}
