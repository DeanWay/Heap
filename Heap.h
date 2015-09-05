/*
Author: Dean Way
*/

#ifndef MIN_HEAP_H
#define MIN_HEAP_H

typedef int(*Compare)(const void *a, const void *b);

typedef struct Heap{
    void **array;//pointer to an array of integers of size Heap->length
    int length;//number of nodes in the heap
    Compare compare;
}Heap;


Heap * newHeap(void **array, size_t lenth, int (*compare)(const void *a, const void *b));

void destroyHeap(Heap *heap);

void Heapify(Heap *heap, int root);

int height(Heap *heap);

int numOfNodes(Heap *heap);

// parent, leftChild, and rightChild funtions return an index, not the nodes at those indexes
// i.e. usage is heap->array[parent(i)];
int parent(int i);

int leftChild(int i);

int rightChild(int i);

void * removeRoot(Heap *heap);

// this function will cause an error if user attempts to insert a node without first removing a node
// or reallocing the array passed in to newHeap() to make space for the new node.
// Reallocing the users array will affect the heap's stored array since the heap's array
// is simply a pointer to the user's array, not a copy of it. 
Heap * insertNode(Heap *heap, void *node);

int isEmpty(Heap *heap);

#endif