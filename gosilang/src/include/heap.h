#ifndef HEAP_H
#define HEAP_H

#include "indirection.h"

// Most Compiler Architecure only support top-down
// top-to-bottom parsing.
//Consequently,Due to nature of quatum computers their
// exist an effiecent to read both mutiple tapes
// yielding mutiple result of the computations.

// This module HEAP_H consist of a MaxHeap ,and MinHeap
// used in symbol_table.h to optimize the algorithm
// lookup of the symbol_table.

typedef struct MinHeap_s MinHeap;
struct MinHeap_s {
    int *array;     // Array to store heap elements
    int capacity;   // Maximum capacity of the heap
    int size;       // Current number of elements in the heap
};

typedef struct MaxHeap_s MaxHeap;
struct MaxHeap_s {
    int *array;     // Array to store heap elements
    int capacity;   // Maximum capacity of the heap
    int size;       // Current number of elements in the heap
};

// Function prototypes for MinHeap
MinHeap *MinHeap_create(int capacity);
void MinHeap_insert(MinHeap *heap, int value);
int MinHeap_extractMin(MinHeap *heap);
void MinHeap_heapify(MinHeap *heap, int index);

// Function prototypes for MaxHeap
MaxHeap *MaxHeap_create(int capacity);
void MaxHeap_insert(MaxHeap *heap, int value);
int MaxHeap_extractMax(MaxHeap *heap);
void MaxHeap_heapify(MaxHeap *heap, int index);

#endif // HEAP_H

