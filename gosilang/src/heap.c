 
#include "heap.h"

// Function to create a MinHeap with a given capacity
MinHeap *MinHeap_create(int capacity) {
    MinHeap *heap = (MinHeap *)malloc(sizeof(MinHeap));
    if (heap == NULL) {
        // Handle memory allocation failure
        return NULL;
    }
    heap->array = (int *)malloc(capacity * sizeof(int));
    if (heap->array == NULL) {
        free(heap);
        return NULL;
    }
    heap->capacity = capacity;
    heap->size = 0;
    return heap;
}

// Function to insert a value into MinHeap
void MinHeap_insert(MinHeap *heap, int value) {
    if (heap->size >= heap->capacity) {
        // Heap is full
        return;
    }
    // Insert value at the end
    int i = heap->size;
    heap->array[i] = value;
    heap->size++;
    // Maintain MinHeap property
    while (i != 0 && heap->array[(i - 1) / 2] > heap->array[i]) {
        // Swap with parent if necessary
        int temp = heap->array[i];
        heap->array[i] = heap->array[(i - 1) / 2];
        heap->array[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

// Function to extract minimum value from MinHeap
int MinHeap_extractMin(MinHeap *heap) {
    if (heap->size <= 0) {
        // Heap is empty
        return -1;
    }
    if (heap->size == 1) {
        heap->size--;
        return heap->array[0];
    }
    // Replace root with last element
    int root = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    // Restore MinHeap property
    MinHeap_heapify(heap, 0);
    return root;
}

// Function to heapify a subtree rooted at given index
void MinHeap_heapify(MinHeap *heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    // Find smallest among root, left child, and right child
    if (left < heap->size && heap->array[left] < heap->array[smallest]) {
        smallest = left;
    }
    if (right < heap->size && heap->array[right] < heap->array[smallest]) {
        smallest = right;
    }
    // If smallest is not root, swap with root and continue heapifying
    if (smallest != index) {
        int temp = heap->array[index];
        heap->array[index] = heap->array[smallest];
        heap->array[smallest] = temp;
        MinHeap_heapify(heap, smallest);
    }
}


// Function to create a MaxHeap with a given capacity
MaxHeap *MaxHeap_create(int capacity) {
    MaxHeap *heap = (MaxHeap *)malloc(sizeof(MaxHeap));
    if (heap == NULL) {
        // Handle memory allocation failure
        return NULL;
    }
    heap->array = (int *)malloc(capacity * sizeof(int));
    if (heap->array == NULL) {
        free(heap);
        return NULL;
    }
    heap->capacity = capacity;
    heap->size = 0;
    return heap;
}

// Function to insert a value into MaxHeap
void MaxHeap_insert(MaxHeap *heap, int value) {
    if (heap->size >= heap->capacity) {
        // Heap is full
        return;
    }
    // Insert value at the end
    int i = heap->size;
    heap->array[i] = value;
    heap->size++;
    // Maintain MaxHeap property
    while (i != 0 && heap->array[(i - 1) / 2] < heap->array[i]) {
        // Swap with parent if necessary
        int temp = heap->array[i];
        heap->array[i] = heap->array[(i - 1) / 2];
        heap->array[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

// Function to extract maximum value from MaxHeap
int MaxHeap_extractMax(MaxHeap *heap) {
    if (heap->size <= 0) {
        // Heap is empty
        return -1;
    }
    if (heap->size == 1) {
        heap->size--;
        return heap->array[0];
    }
    // Replace root with last element
    int root = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    // Restore MaxHeap property
    MaxHeap_heapify(heap, 0);
    return root;
}

// Function to heapify a subtree rooted at given index
void MaxHeap_heapify(MaxHeap *heap, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    // Find largest among root, left child, and right child
    if (left < heap->size && heap->array[left] > heap->array[largest]) {
        largest = left;
    }
    if (right < heap->size && heap->array[right] > heap->array[largest]) {
        largest = right;
    }
    // If largest is not root, swap with root and continue heapifying
    if (largest != index) {
        int temp = heap->array[index];
        heap->array[index] = heap->array[largest];
        heap->array[largest] = temp;
        MaxHeap_heapify(heap, largest);
    }
}

