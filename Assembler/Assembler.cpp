#include "Assembler.h"
#include <iostream>
#include <sstream>
#include <list>

using namespace std;

Assembler::Assembler(ParsedTx input) {

    // Iterate over vectors
    for (int i = 0; i < input.size() -1; i++) {
        // Parse out Data
        Data data = input[i].first;

        // Get TxID
        string txID = data[0];

        // Get Fee
        int fee = stoi(data[1]);

        // Get Weight
        int weight = stoi(data[2]);

        // Get Parents

        Parents parent = input[i].second;
        if (parent.at(0).find(';')) {
            string temp = parent[0];
            string tempBuf;
            stringstream ss(temp);
            parent.clear();

            do {
                getline(ss,tempBuf, ';');
                if (!tempBuf.empty()) {
                    parent.push_back(tempBuf);
                    tempBuf.clear();
                }
            }
            while(!tempBuf.empty());
            // else Transaction only had one parent tx or get last parent txid
            getline(ss, tempBuf, ' ');
            //cout << temp << endl;
            if (!tempBuf.empty()) {
                parent.push_back(tempBuf);
            }
        }

        Transaction* newTransaction = new Transaction(txID, fee, weight, parent);
        store.insert(*newTransaction);
    }
}

// Recursive Algorithm to get Job Order
JobOrder Assembler::schedule() {

    // Current Weight Proxy
    int CWP = CURRENT_WEIGHT;

    list<Transaction> output;

    // First Check if Store is Empty
    if (!store.empty()) {
        while(!store.empty() && (CWP < WEIGHT_LIMIT)) {

            // Else continue recursive call
            Transaction candidate = store.top();
            //cout << candidate.getFee() << endl;
            Parents check = candidate.getParentTxs();

            // If no parents add to order
            if(check.empty())  {
                if(CWP + candidate.getFee() > WEIGHT_LIMIT) {
                    cout << CURRENT_WEIGHT << endl;
                    return order;
                } else {
                    order.push_back(candidate);
                    CURRENT_WEIGHT += candidate.getWeight();
                    CWP = CURRENT_WEIGHT;
                    store.pop();
                }
            } else {

                // Check if Parents are already in the Output
                // Ran out of time
                store.pop();

            }
        }
    }

    cout << CURRENT_WEIGHT << endl;
    cout << WEIGHT_LIMIT << endl;
   return order;


}

