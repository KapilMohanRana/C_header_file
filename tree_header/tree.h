#ifndef ADVTREE_H
#define ADVTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*compareFunc)(const void *, const void *);
typedef void (*printFunc)(const void *);

typedef struct Tree
{
	void *data;
	struct Tree *left;
	struct Tree *right;
} Tree;

// This is to create the node of Tree
Tree *createNode(void *, size_t);

// This is to insert node in the Tree
Tree *insertData(Tree *, void *, size_t, compareFunc compare);

// This is to delete the tree
Tree *deleteTree(Tree *, void (*freeFunc)(void *));

// This is for inOrderTraversal
void inOrderTraversal(Tree *, printFunc print);

// This is for preOrderTraversal
void preOrderTraversal(Tree *, printFunc print);

// This is for postOrderTraversal
void postOrderTraversal(Tree *, printFunc print);

#endif
