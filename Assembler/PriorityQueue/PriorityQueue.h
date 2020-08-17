#ifndef BINARYHEAP_H
#define BINARYHEAP_H
#include "../../Transaction/Transaction.h"

class PriorityQueue {
private:
    vector<Transaction> queue;
    int left(int parent);
    int right(int parent);
    int parent(int child);
    void HeapUp(int index);
    void HeapDown(int index);

public:
    // Initialize Priority Queue
    PriorityQueue() {};

    // Return Size
    int size();

    // To determine wether or not PQ is empty
    bool empty();

    // Insert element into PQ
    void insert(Transaction Element);

    // Remove Largest Element
    void pop();

    // Return top element, but don't pop
    Transaction top();


};


#endif //BINARYHEAP_H
