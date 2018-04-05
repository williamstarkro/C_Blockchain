//
// Created by William on 4/4/18.
//

#ifndef C_TUT_TRANSACTION_H
#define C_TUT_TRANSACTION_H

#include <iostream>
#include <vector>
#include <sstream>
#include "sha256.h"
#include "Ecdsa.hpp"

using namespace std;

class Transaction {
public:
    string transactionID; //hash of transaction
    string sender; //senders public key
    string reciepient; //recepients key
    float value;
    char signature[];  // prevents anyone else from spending funds in your wallet

    vector<TransactionInput> inputs;
    vector<TransactionOutput> outputs;

    Transaction(string from, string to, float value,  vector<TransactionInput> inputs) {
        sender = from;
        reciepient = to;
        this->value = value;
        this->inputs = inputs;
    };

    void generateSignature(string privateKey) {

        stringstream ss;
        ss << sender << reciepient << value;
        signature = Ecdsa::signWithHmacNonce(privateKey, ss.str());
    }

    bool verifiySignature() {

        stringstream ss;
        ss << sender << reciepient << value;;
        return Ecdsa::verify(sender, ss, signature);
    }

private:
    static int _sequence = 0;

    string _calculateHash() {
        _sequence++;
        stringstream ss;
        ss << sender << reciepient << value << _sequence;

        return sha256(ss.str());
    };
};


#endif //C_TUT_TRANSACTION_H
