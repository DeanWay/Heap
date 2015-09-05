/*
Author: Dean Way
*/
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "Heap.h"


Heap * newHeap(void *array[], size_t length, int (*compare)(const void *a, const void *b)){
    int i;
    Heap *heap=(Heap *)malloc(sizeof(Heap));
    heap->length=(int)length;
    heap->array=array;
    heap->compare=compare;
    for(i=(heap->length/2)-1; i>=0; i--){
        Heapify(heap, i);
    }
    
    return heap;
}

void destroyHeap(Heap *heap){
    free(heap);
}

int height(Heap *heap){
    return ceil(log2(heap->length));
}

int numOfNodes(Heap *heap){
    if (heap!=NULL){
        return heap->length;
    }
    else{
        return 0;
    }
}

int parent(int i){
    return (i-1)/2;
}

int leftChild(int i){
    return (i*2)+1;;
}

int rightChild(int i){
    return (i*2)+2;
}

void Heapify(Heap *heap, int root){
    if(NULL==heap){
        return;
    }
    int rChild, lChild, smallest;
    lChild=(root*2)+1;
    rChild=lChild+1;
    smallest=root;
    
    
    if(lChild < heap->length && heap->compare((heap->array[smallest]), (heap->array[lChild]))==1){
        smallest=lChild;
    }
    
    if(rChild < heap->length && heap->compare((heap->array[smallest]), (heap->array[rChild]))==1){
        smallest=rChild;
    }
    
    if (root!=smallest){
        void *temp=heap->array[root];
        heap->array[root]=heap->array[smallest];
        heap->array[smallest]=temp;
        Heapify(heap, smallest);
    }
}

void siftUp(Heap *heap, int node){
    if(NULL==heap){
        return;
    }
    if (node > 0){
        if(heap->compare(heap->array[node], heap->array[parent(node)])==-1){
            void *temp=heap->array[node];
            heap->array[node]=heap->array[parent(node)];
            heap->array[parent(node)]=temp;
            siftUp(heap, parent(node));
        }
    }
}

void *removeRoot(Heap *heap){
    if(isEmpty(heap)){
        return NULL;
    }
    void *root=heap->array[0];
    heap->array[0]=heap->array[heap->length-1];
    heap->length-=1;
    Heapify(heap, 0);
    return root;
}

/* FIXME:
 * This operation is Dangerous. If the backing array does not
 * have enough space allocated to support the new node, 
 * a segmenation fault will occur
 */
Heap * insertNode(Heap *heap, void *node){
    heap->length += 1;
    heap->array[heap->length - 1] = node;

    siftUp(heap, heap->length - 1);
    
    return heap;
}

int isEmpty(Heap *heap){
    if(heap->length == 0){
        return 1;
    }
    else{
        return 0;
    }
}

