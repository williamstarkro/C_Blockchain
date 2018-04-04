#include "Blockchain.h"

Blockchain::Blockchain() {
    _vChain.emplace_back(Block(0, "Genesis Block"));
    _nDifficulty = 4;
}

void Blockchain::AddBlock(Block bNew) {
    bNew.sPrevHash = _GetLastBlock().GetHash();
    bNew.MineBlock(_nDifficulty);
    _vChain.push_back(bNew);
}

Block Blockchain::_GetLastBlock() const {
    return _vChain.back();
}

bool Blockchain::isChainValid() {
    Block currentBlock = _GetLastBlock();
    Block previousBlock = _GetLastBlock();

    //loop through blockchain to check hashes:
    for(int i=1; i < _vChain.size(); i++) {
        currentBlock = _vChain[i];
        previousBlock = _vChain[i-1];
        //compare registered hash and calculated hash:
        if(currentBlock.GetHash() != currentBlock._CalculateHash() ){
            cout << "Current Hashes not equal";
            return false;
        }
        //compare previous hash and registered previous hash
        if(previousBlock.GetHash() != currentBlock.sPrevHash ) {
            cout << "Previous Hashes not equal";
            return false;
        }
    }
    return true;
}