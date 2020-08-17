#include "Transaction.h"

#include <utility>

// Initialize Transaction Object
Transaction::Transaction(string txId, int fee, int weight, vector<string> parentTxs) {
    TxId = move(txId);
    Fee = fee;
    Weight = weight;
    ParentTxs = move(parentTxs);
}

// Get Transaction ID
string Transaction::getTxID(){
    return TxId;

}

// Get Fee in Sats of this Transaction
int Transaction::getFee(){
    return Fee;
}

// Get weight of this Transaction
int Transaction::getWeight(){
    return Weight;
}

// Get Parent Transactions
vector<string> Transaction::getParentTxs(){
    return ParentTxs;
}