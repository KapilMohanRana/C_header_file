#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    void *data;
    int size;
    int top;
    size_t elesize;
} Stack;

// Creates a new Stack
Stack *newStack(int, int);

// Resize the Stack
int sResize(Stack *, int);

// Push Element in a Stack
void push(Stack *, void *);

// Removes a element from a Stack
void pop(Stack *, void *);

// Let you see the top element of a Stack
void peek(Stack *, void *);

// Deletes the whole Stack
void freeStack(Stack *);

// Returns true(1) if Stack is empty
int isEmpty(Stack *);

// Returns true(1) if Stack is full
int isFull(Stack *);