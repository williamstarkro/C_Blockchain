#include "Blockchain.h"
#include "Wallet.h"
#include <vector>
#include "Transaction.h"



int main() {

    Blockchain bChain = Blockchain();
    Wallet walletA = Wallet();
    Wallet walletB = Wallet();

    cout << "Private and public keys:" << endl;
    walletA.GeneratePublicKey();
    walletB.GeneratePublicKey();
    //Create a test transaction from WalletA to walletB
    Transaction transaction = Transaction(walletA.publicKey, walletB.publicKey, 5, 0);
    transaction.generateSignature(walletA.GetPrivateKey());
    //Verify the signature works and verify it from the public key
    cout << "Is signature verified";
    cout << transaction.verifiySignature();

    return 0;
};