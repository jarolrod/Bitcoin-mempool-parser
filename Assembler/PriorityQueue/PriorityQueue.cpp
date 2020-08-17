#include "PriorityQueue.h"

// Get Index of Parent
int PriorityQueue::parent(int childIndex) {
    return((childIndex - 1) / 2);
}

// Get Index of Right Child
int PriorityQueue::right(int parentIndex) {
    return((2 * parentIndex) + 2);
}

// Get Index of Left Child
int PriorityQueue::left(int parentIndex) {
    return((2 * parentIndex) + 1);
}

void PriorityQueue::HeapDown(int index) {

    // Get Left Child
    int leftIndex = left(index);

    // Get right child
    int rightIndex = right(index);

    // To hold Largest Element
    int largest = index;

    // Left is largest
    if ((leftIndex < size()) && (queue[leftIndex].getFee() > queue[rightIndex].getFee())) {
        largest = leftIndex;
    }

    // Right is largest
    if ((rightIndex < size()) && (queue[rightIndex].getFee() > queue[leftIndex].getFee())) {
        largest = rightIndex;
    }

    if(largest != index) {
        swap(queue[index], queue[largest]);
        HeapDown(largest);
    }


}

// HeapDown
void PriorityQueue::HeapUp(int index) {
    // Check if node[i] or node[i] parent cause violation
    if(index && queue[parent(index)].getFee() < queue[index].getFee()) {
        // Violation Found: Swap
        swap(queue[index], queue[parent(index)]);

        // Recursive Call
        HeapUp(parent(index));
    }

}

// Return size of PQ
int PriorityQueue::size() {
    return queue.size();
}

// Check if PQ is empty
bool PriorityQueue::empty() {

    return queue.empty();
}

// remove top element
void PriorityQueue::pop() {
    // Check that PQ is not empty
    if (!empty()) {
        // Move top element to back
        queue[0] = queue.back();
        queue.pop_back();

        // Next -> HeapDown
        HeapDown(0);
    } else {
        // Else error

    }
}

// Peek at top element
Transaction PriorityQueue::top() {
    // Check that PQ is not empty
    if (!empty()) {
        return queue.at(0);
    } else {
        // Else error

    }
}

// Insert into priority queue
void PriorityQueue::insert(Transaction elem) {

    // Insert Element at the end of the queue
    queue.push_back(elem);

    // Call HeapUp at last position
    HeapUp(queue.size() - 1);

}