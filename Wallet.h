//
// Created by William on 4/4/18.
//

#ifndef C_TUT_WALLET_H
#define C_TUT_WALLET_H

#include <iostream>

using namespace std;

class Wallet {
public:
    int p, q, n, t, flag;
    char e[65], d[65], temp[65], j, en[65], i;
    char msg[65];
    string publicKey;
    void GeneratePublicKey();
    void ce();
    int prime(long int);
    long int cd(long int);
    void encrypt(char m[]);
    Wallet();


private:
    void _PrivateKeyGenerator();
    string _privateKey;
};


#endif //C_TUT_WALLET_H
