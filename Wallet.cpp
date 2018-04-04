#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Wallet.h"
#include <sstream>
#include <iostream>
#include <math.h>

#define StringLength (256/4)

using namespace std;

Wallet::Wallet(){
}

void Wallet::GeneratePublicKey() {

    char cStrHex[StringLength+1] = {0};

    // Seed random:
    srand((unsigned int) time(0));

    // Fill the char buffer
    int i=0;
    for(; i < StringLength; i++){
        sprintf(cStrHex+i, "%x", rand() % 16);
    }

    publicKey = cStrHex;

    _PrivateKeyGenerator();
}

//Program for RSA asymmetric cryptographic algorithm
//for demonstration values are relatively small compared to practical application

//to find gcd
int gcd(int a, int h)
{
    int temp;
    while(1)
    {
        temp = a%h;
        if(temp==0)
            return h;
        a = h;
        h = temp;
    }
}

void Wallet::_PrivateKeyGenerator() {

    strcpy(msg, publicKey.c_str());
    char m[65] = {0};
    msg[sizeof(msg) - 1] = 0;

    p = 23;
    q = 41;

    for (int i = 0; msg[i] != '\0'; i++) {
        m[i] = msg[i];
    }
    n = p * q;
    t = (p - 1) * (q - 1);

    Wallet::ce();

    Wallet::encrypt(m);
}

void Wallet::ce() {
    int k;
    k = 0;
    for (int i = 2; i < t; i++)
    {
        if (t % i == 0) {
            continue;
        }
        flag = prime(i);
        if (flag == 1 && i != p && i != q)
        {
            e[k] = i;
            flag = cd(e[k]);
            if (flag > 0)
            {
                d[k] = flag;
                k++;
            }
            if (k == 99)
                break;
        }
    }
}

int Wallet::prime(long int pr)
{
    int i;
    int j = sqrt(pr);
    for (i = 2; i <= j; i++)
    {
        if (pr % i == 0)
            return 0;
    }
    return 1;
}

long int Wallet::cd(long int x)
{
    long int k = 1;
    while (1)
    {
        k = k + t;
        if (k % x == 0)
            return (k / x);
    }
}

void Wallet::encrypt(char m[])
{
    long int pt, ct, key = e[0], k, len;
    i = 0;
    len = strlen(msg);
    while (i != len)
    {
        pt = m[i];
        pt = pt - 96;
        k = 1;
        for (j = 0; j < key; j++)
        {
            k = k * pt;
            k = k % n;
        }
        temp[i] = k;
        ct = k + 96;
        en[i] = ct;
        i++;
    }
    en[i] = -1;
    _privateKey = en;
    cout << _privateKey;
}
