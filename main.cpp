#include <iostream>
#include <cctype>
#include "modAlphaCipher.h"
#include <locale>
#include <codecvt>
#include <typeinfo>
using namespace std;
void check(const wstring& Text, const wstring& key, const bool destructCipherText=false)
{
    try {
        wstring cipherText;
        wstring decryptedText;
        Cipher cipher(key);
        cipherText = cipher.encrypt(Text);
        if (destructCipherText)
            cipherText.front() = tolower(cipherText.front());
        decryptedText = cipher.decrypt(cipherText);
        wcout<<"key="<<key<<endl;
        wcout<<Text<<endl;
        wcout<<cipherText<<endl;
        wcout<<decryptedText<<endl;
    } catch (const cipher_error & e) {
        cerr<<"Error: "<<e.what()<<endl;
    }
}
int main(int argc, char **argv)
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    wcout<<L'-'<<endl;
    check(L"КЛАВИАТУРА",L"ХЕЛЛОУ");
    wcout<<L'-'<<endl;
    check(L"КЛАВИАТУРА",L"");
    wcout<<L'-'<<endl;
    check(L"КЛАВИАТУРА",L"Х1Е2Л3Л4О5У6");
    wcout<<L'-'<<endl;
    check(L"КЛАВИА ТУРА",L"ХЕЛЛОУ");
    wcout<<L'-'<<endl;
    check(L"КЛАВИАТУРА",L"ХЕЛЛОУ",true);
    wcout<<L'-'<<endl;
    check(L"12345789",L"ХЕЛЛОУ");
    wcout<<L'-'<<endl;
    return 0;
}