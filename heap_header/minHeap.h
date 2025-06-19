#ifndef MINHEAP_H
#define MINHEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to Compare values of two nodes
typedef int (*compareFunc)(const void *, const void *);

// Print the value on the screen
typedef void (*printFunc)(const void *);

// Structure for creating Heap (Min Heap)
typedef struct MinHeap
{
    void *ele;
    int ind;
    int capacity;
    size_t size;
    compareFunc compare;
    printFunc print;
} MinHeap;

// Creates a Heap
MinHeap *createHeap(int, size_t, compareFunc, printFunc);

// Swap the values of two nodes in the Heap
void swap(void *, void *, size_t);

// Make the Heap sorted again after inserting a new value
void heapifyUp(MinHeap *, int);

// Insert a node in Heap
void insert(MinHeap *, void *);

// Make the Heap sorted again after deleting a node
void heapifyDown(MinHeap *, int);

// Deletes the root of Heap
void getMinElement(MinHeap *, void *);

// Prints the value of Heap
void printHeap(MinHeap *);

#endif