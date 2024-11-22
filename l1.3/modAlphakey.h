#ifndef MODALPHAKEY_H
#define MODALPHAKEY_H

#include <iostream>
#include <string>

using namespace std;

class modAlphakey {
public:
    modAlphakey(int key);
    wstring encrypt(const wstring& text);
    wstring decrypt(const wstring& text);

private:
    int key;
    static wchar_t shiftChar(wchar_t c, int key);
};

#endif // MODALPHAKEY_H
