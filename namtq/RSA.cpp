// C++ Program for implementation of RSA Algorithm

#include <bits/stdc++.h>

using namespace std;

// Function to compute base^expo mod m
int power(int base, int expo, int m) {
    int res = 1;
    base = base % m;
    while (expo > 0) {
        if (expo & 1)
            res = (res * 1LL * base) % m;
        base = (base * 1LL * base) % m;
        expo = expo / 2;
    }
    return res;
}

// Function to find modular inverse of e modulo phi(n)
// Here we are calculating phi(n) using Hit and Trial Method
// but we can optimize it using Extended Euclidean Algorithm
int modInverse(int e, int phi) {
    for (int d = 2; d < phi; d++) {
        if ((e * d) % phi == 1)
            return d;
    }
    return -1;
}

// RSA Key Generation
void generateKeys(int &e, int &d, int &n) {
    int p = 7919;
    int q = 1009;
    
    n = p * q;
    int phi = (p - 1) * (q - 1);

    // Choose e, where 1 < e < phi(n) and gcd(e, phi(n)) == 1
    for (e = 2; e < phi; e++) {
        if (__gcd(e, phi) == 1)
            break;
    }

    // Compute d such that e * d = 1 (mod phi(n))
    d = modInverse(e, phi);
}

// Encrypt message using public key (e, n)
int encrypt(int m, int e, int n) {
    return power(m, e, n);
}

// Decrypt message using private key (d, n)
int decrypt(int c, int d, int n) {
    return power(c, d, n);
}

int main() {
    int e, d, n;
    
    // Key Generation
    generateKeys(e, d, n);
  
    cout << "Public Key (e, n): (" << e << ", " << n << ")\n";
    cout << "Private Key (d, n): (" << d << ", " << n << ")\n";

    // Message
    int M = 123;
    cout << "Original Message: " << M << endl;

    // Encrypt the message
    int C = encrypt(M, e, n);
    cout << "Encrypted Message: " << C << endl;

    // Decrypt the message
    int decrypted = decrypt(C, d, n);
    cout << "Decrypted Message: " << decrypted << endl;

    return 0;
}
