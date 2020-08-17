#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include "../Helper/Common.h"
#include "../Transaction/Transaction.h"
#include "PriorityQueue/PriorityQueue.h"
#include <string>

using TransactionBase = PriorityQueue;
using JobOrder = vector<Transaction>;

class Assembler {

private:
    // Cannot Exceed this weight limit
    const int WEIGHT_LIMIT = 4000000;

    int CURRENT_WEIGHT = 0;

    TransactionBase store;

    JobOrder order;

    // Candidates currently in the backburner
    PriorityQueue backBurner;

    unordered_map<string, int> query;

public:
    Assembler(ParsedTx input);
    JobOrder schedule();
};









#endif //ASSEMBLER_H
