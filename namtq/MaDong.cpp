#include <iostream>
#include <string>

using namespace std;

#include <iostream>
#include <string>

using namespace std;

string xorBinary(const string& binaryStr, const string& key) {
    string result = binaryStr;
    for (size_t i = 0; i < binaryStr.length(); ++i) {
        result[i] = (binaryStr[i] == key[i % key.length()]) ? '0' : '1';
    }
    return result;
}

int main() {
    string binaryStr, key;

    cout << "Nhap chuoi nhi phan 8 bit: ";
    cin >> binaryStr;

    cout << "Nhap khoa 4 bit: ";
    cin >> key;

    string encrypted = xorBinary(binaryStr, key);
    cout << "Sau khi ma hoa: " << encrypted << endl;

    string decrypted = xorBinary(encrypted, key);
    cout << "Sau khi giai ma: " << decrypted << endl;

    return 0;
}

/*
string xorCipher(const string& text, char key) {
    string result = text;
    for (size_t i = 0; i < result.length(); ++i) {
        result[i] ^= key;
    }
    return result;
}

int main() {
    string inputText;
    char key;

    cout << "Nhap chuoi van ban: ";
    getline(cin, inputText);

    cout << "Nhap mot ky tu lam khoa: ";
    cin >> key;

    string encryptedText = xorCipher(inputText, key);
    cout << "\nChuoi sau khi ma hoa: " << encryptedText << endl;

    string decryptedText = xorCipher(encryptedText, key);
    cout << "Chuoi sau khi giai ma: " << decryptedText << endl;

    return 0;
}
*/
