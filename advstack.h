#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct {
void *data;
int size;
int top;
size_t elesize;
}Stack;

// Creates a new Stack
Stack *newStack(int size,int elesize){
Stack *s = (Stack *)malloc(sizeof(Stack));
if(s == NULL){
return NULL;
}
s->data = malloc(size*elesize);
if(s->data == NULL){
free(s);
return NULL;
}
s->top = -1;
s->size = size;
s->elesize = elesize;
return s;
}

// Reallocate the size of stack according to the need of user
int sResize(Stack *s,int newSize){
void *ptr = realloc(s->data,newSize*s->elesize);
if(ptr == NULL) {
return 0;
}
s->data = ptr;
s->size = newSize;
return 1;
}

// PUSH the element at the top of the stack
void push(Stack *s,void *data) {
if(s->top == s->size-1)
printf("Stack is full\n");
else {
s->top++;
void *target = (char *)s->data + s->top * s->elesize;
memcpy(target,data,s->elesize);
printf("Element inserted\n");
}
}

// POP the top element and store it at the address that the user passed in the arguments
void pop(Stack *s,void *ans) {
if(s->top == -1)
printf("Stack is Empty\n");
else {
void *src = (char *)s->data + s->top * s->elesize;
memcpy(ans,src,s->elesize);
printf("Element deleted\n");
s->top--;
}
}

// Gives the top element of the stack and stores it at the address that user passed in the argument
void peek(Stack *s,void *ans) {
if(s->top == -1)
printf("Stack is Empty\n");
else {
void *src = (char *)s->data + s->top * s->elesize;
memcpy(ans,src,s->elesize);
}
}

// Free the allocated space for both stack array and stack structure
void freeStack(Stack *s) {
if(s != NULL){
free(s->data);
free(s);
printf("Stack is freed\n");
}
}

// Checks if the Stack is empty or not and return 1 if stack is empty and 0 if stack is not empty
int isEmpty(Stack *s) {
return s->top == -1;
}

// Checks If the Stack is full or not and return 1 if stack is full and 0 if stack is not full
int isFull(Stack *s) {
return s->top == s->size-1;
}
