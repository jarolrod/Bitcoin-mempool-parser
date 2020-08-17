#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include "../Helper/Common.h"


class Transaction {

private:
    // Transaction ID
    string TxId;

    // Fee in Sats of this Transaction
    int Fee;

    // Weight of this Transaction
    int Weight;

    // List of Parent Transactions for this Transaction
    vector<string> ParentTxs;


public:

    // Initialize Transaction Object
    Transaction(string txId, int fee, int weight, vector<string> parentTxs);

    // Get Transaction ID
    string getTxID();

    // Get Fee in Sats of this Transaction
    int getFee();

    // Get weight of this Transaction
    int getWeight();

    // Get Parent Transactions
    vector<string> getParentTxs();


};


#endif //TRANSACTION_H
