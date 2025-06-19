#include "minHeap.h"

// Create a Heap (Min Heap)
MinHeap *createHeap(int capacity, size_t size, compareFunc compare, printFunc print)
{
    MinHeap *heap = (MinHeap *)malloc(sizeof(MinHeap));
    if (heap == NULL)
    {
        return NULL;
    }
    heap->ele = malloc(capacity * size);
    if (heap->ele == NULL)
    {
        free(heap);
        return NULL;
    }
    heap->ind = -1;
    heap->capacity = capacity;
    heap->size = size;
    heap->compare = compare;
    heap->print = print;
    return heap;
}

// Swap values of two nodes
void swap(void *a, void *b, size_t size)
{
    void *temp = malloc(size);
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
}

// Check for the smallest element and take it to the root after inserting a new node in Heap
void heapifyUp(MinHeap *heap, int ind)
{
    if (ind <= 0)
        return;
    int parent = (ind - 1) / 2;
    void *child = (char *)heap->ele + ind * heap->size;
    void *parentptr = (char *)heap->ele + parent * heap->size;

    // while (ind > 0 && heap->compare(parentptr, child))
    // {
    //     swap(child, parentptr, heap->size);
    //     ind = parent;
    //     parent = (ind - 1) / 2;
    //     child = (char *)heap->ele + ind * heap->size;
    //     parentptr = (char *)heap->ele + parent * heap->size;
    // }

    if (heap->compare(child, parentptr) > 0)
    {
        swap(child, parentptr, heap->size);
        heapifyUp(heap, parent);
    }
}

// Insert a new Node in Heap
void insert(MinHeap *heap, void *data)
{
    if (heap->ind == heap->capacity)
    {
        ("Heap is full\n");
        return;
    }
    heap->ind++;
    memcpy((char *)heap->ele + heap->ind * heap->size, data, heap->size);
    heapifyUp(heap, heap->ind);
}

// Check for the smallest element and take it to the root after deleting a node from Heap
void heapifyDown(MinHeap *heap, int ind)
{
    int leftChild = 2 * ind + 1;
    int rightChild = 2 * ind + 2;
    int larg = ind;
    // void *first = (char *)heap->ele + leftChild * heap->size;
    // void *second = (char *)heap->ele + rightChild * heap->size;
    // void *largPtr = (char *)heap->ele + larg * heap->size;
    // void *indPtr = (char *)heap->ele + ind * heap->size;

    if (leftChild < heap->ind && heap->compare((char *)heap->ele + leftChild * heap->size, (char *)heap->ele + larg * heap->size))
    {
        larg = leftChild;
        // largPtr = (char *)heap->ele + larg * heap->size;
    }
    if (rightChild < heap->ind && heap->compare((char *)heap->ele + rightChild * heap->size, (char *)heap->ele + larg * heap->size))
    {
        larg = rightChild;
        // largPtr = (char *)heap->ele + larg * heap->size;
    }

    if (larg != ind)
    {
        swap((char *)heap->ele + ind * heap->size, (char *)heap->ele + larg * heap->size, heap->size);
        heapifyDown(heap, larg);
    }
}

// Deletes the root node from Heap
void getMinElement(MinHeap *heap, void *d)
{
    if (heap->ind == -1)
    {
        printf("Heap is empty\n");
        return;
    }
    memcpy(d, (char *)heap->ele, heap->size);
    memcpy((char *)heap->ele, (char *)heap->ele + heap->ind * heap->size, heap->size);
    heap->ind--;
    heapifyDown(heap, 0);
}

// Print the values in Heap
void printHeap(MinHeap *heap)
{
    if (heap->ind == -1)
    {
        printf("Heap is empty\n");
    }
    else
    {
        for (int i = 0; i <= heap->ind; i++)
        {
            void *ptr = (char *)heap->ele + i * heap->size;
            heap->print(ptr);
        }
        printf("\n");
    }
}