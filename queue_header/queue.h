#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure of the queue allocated in the memory
typedef struct
{
  void *data;
  int size;
  int first;
  int last;
  size_t elesize;
} Queue;

// function definition

// Creates a new Queue
Queue *newQueue(int, int);

// Resize the Queue
int qResize(Queue *, int);

// Delete the Queue
void freeQueue(Queue *);

// Insert a value in Queue
void insert(Queue *, void *);

// Delete a value from Queue
void delele(Queue *, void *);

// Givs you the last elemented inserted in Queue
void peek(Queue *, void *);

// Return true(1) if Queue is empty
int qIsEmpty(Queue *);

// Return true(1) if Queue is Full
int qIsFull(Queue *);

#endif