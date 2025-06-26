#include "advTree.h"

// This Function creates a Node for the Tree
Tree *createNode(void *data, size_t size)
{
    Tree *node = (Tree *)malloc(sizeof(Tree));
    if (node == NULL)
        return NULL;
    node->data = malloc(size);
    if (node->data == NULL)
    {
        free(node);
        return NULL;
    }
    memcpy(node->data, data, size);
    node->left = NULL;
    node->right = NULL;
    return node;
}

// This is used to insert data inside Tree
Tree *insertData(Tree *node, void *data, size_t size, compareFunc compare)
{
    if (node == NULL)
    {
        return createNode(data, size);
    }
    else if (compare(node->data, data))
    {
        node->left = insertData(node->left, data, size, compare);
    }
    else if (compare(data, node->data))
    {
        node->right = insertData(node->right, data, size, compare);
    }
    return node;
}

Tree *deleteTree(Tree *node, void (*freeFunc)(void *))
{
    if (node != NULL)
    {
        deleteTree(node->left, freeFunc);
        deleteTree(node->right, freeFunc);
        if (freeFunc != NULL)
        {
            freeFunc(node->data);
        }
        free(node);
    }
    return NULL;
}

void preOrderTraversal(Tree *node, printFunc print)
{
    if (node != NULL)
    {
        print(node->data);
        preOrderTraversal(node->left, print);
        preOrderTraversal(node->right, print);
    }
}

void inOrderTraversal(Tree *node, printFunc print)
{
    if (node != NULL)
    {
        inOrderTraversal(node->left, print);
        print(node->data);
        inOrderTraversal(node->right, print);
    }
}

void postOrderTraversal(Tree *node, printFunc print)
{
    if (node != NULL)
    {
        postOrderTraversal(node->left, print);
        postOrderTraversal(node->right, print);
        print(node->data);
    }
}