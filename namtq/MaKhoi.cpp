#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string xorBlock(const string& block, const string& key) {
    string result = block;
    for (int i = 0; i < 4; ++i) {
        result[i] = (block[i] == key[i]) ? '0' : '1';
    }
    return result;
}

string shiftLeft(const string& key) {
    return key.substr(1) + key[0];
}

int main() {
    ifstream inFile("D:\\Working 2025\\DNU\\1.An toan bao mat\\Codes\\input.txt");
    ofstream outFile("D:\\Working 2025\\DNU\\1.An toan bao mat\\Codes\\output.txt");

    string input, key, encrypted = "", tempKey;

    getline(inFile, input);
    getline(inFile, key);

    tempKey = key;

    for (int i = 0; i < 32; i += 4) {
        string block = input.substr(i, 4);
        string encryptedBlock = xorBlock(block, tempKey);
        encrypted += encryptedBlock;
        tempKey = shiftLeft(tempKey);
    }

    outFile << "Ma hoa: " << encrypted << endl;

    tempKey = key;
    string decrypted = "";

    for (int i = 0; i < 32; i += 4) {
        string block = encrypted.substr(i, 4);
        string decryptedBlock = xorBlock(block, tempKey);
        decrypted += decryptedBlock;
        tempKey = shiftLeft(tempKey);
    }

    outFile << "Giai ma: " << decrypted << endl;

    inFile.close();
    outFile.close();
	cout << "Da ma hoa va giai ma ra file output.txt! Done." << endl;
    return 0;
}

