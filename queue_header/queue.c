#include "queue.h"

// Creates a new Queue of size given by the user
Queue *newQueue(int size, int elesize)
{
  Queue *queue = malloc(sizeof(Queue));
  if (queue == NULL)
    return NULL;
  queue->data = malloc(size * elesize);
  if (queue->data == NULL)
  {
    free(queue);
    return NULL;
  }
  queue->first = -1;
  queue->last = -1;
  queue->size = size;
  queue->elesize = elesize;
  return queue;
}

// Resize the queue size according to the user
int qResize(Queue *queue, int n)
{
  void *ptr = realloc(queue->data, n * queue->elesize);
  if (ptr == NULL)
  {
    return 0;
  }
  queue->data = ptr;
  queue->size = n;
  return 1;
}

// free the queue space allocated in the memory
void freeQueue(Queue *queue)
{
  if (queue != NULL)
  {
    free(queue->data);
    free(queue);
    printf("Queue is freed\n");
  }
}

// Insert at the end of the queue
void insert(Queue *queue, void *data)
{
  if (queue->last == queue->size - 1)
    printf("Queue is full\n");
  else if (queue->last == -1)
  {
    queue->first++;
    queue->last++;
    void *ins = (char *)queue->data + queue->last * queue->elesize;
    memcpy(ins, data, queue->elesize);
    printf("Element inserted\n");
  }
  else
  {
    queue->last++;
    void *ins = (char *)queue->data + queue->last * queue->elesize;
    memcpy(ins, data, queue->elesize);
    printf("Element inserted\n");
  }
}

// Deletes the first element inserted in the queue and gives it to the user
void delele(Queue *queue, void *ans)
{
  if (qIsEmpty(queue))
  {
    printf("Queue is empty\n");
  }
  else
  {
    void *src = (char *)queue->data + queue->first * queue->elesize;
    memcpy(ans, src, queue->elesize);
    queue->first++;
    printf("Element is deleted\n");
  }
}

// Store the last element inserted in the queue at the address given by the user
void peek(Queue *queue, void *ans)
{
  if (qIsEmpty(queue))
    printf("Queue is empty\n");
  else
  {
    void *src = (char *)queue->data + queue->last * queue->elesize;
    memcpy(ans, src, queue->elesize);
  }
}

// tells the user if queue is empty or not
int qIsEmpty(Queue *queue)
{
  if (queue->first == -1 && queue->last == -1)
    return 1;
  return queue->first > queue->last; // return 1 if queue is empty else return 0
}

// tells the user if queue is full or not
int qIsFull(Queue *queue)
{
  return queue->last == queue->size - 1; // return 1 if queue is full else return 0
}
