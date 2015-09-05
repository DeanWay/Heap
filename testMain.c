#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"

struct ex{
    int data;
};

int compare (const void *a, const void *b){
//    printf("%d > %d = %d\n", *(int*)a, *(int *)b, *(int*)a > *(int*)b);
    const struct ex *s1 = a;
    const struct ex *s2 = b;
    if (s1->data < s2->data){
        return -1;
    }
    else if (s1->data > s2->data){
        return 1;
    }
    else{
        return 0;
    }
}

int main (void){
    int i ,k;
    struct ex *array[8];
    for (i=0; i<8; i++) {
        array[i]=(struct ex *)malloc(sizeof(struct ex));
    }
    array[0]->data= 1;
    array[1]->data= 76;
    array[2]->data= 8;
    array[3]->data= 3;
    array[4]->data= 12;
    array[5]->data= 22;
    array[6]->data= 4;
    array[7]->data= 2;
    
    Heap *heap=newHeap((void **)array, sizeof(array)/sizeof(array[0]), compare);

    for(i=0; i < heap->length; i++){
        printf("%d\n", array[i]->data);
    }
    
    struct ex *temp;
    printf("\n");
    temp=(struct ex*)removeRoot(heap);
    printf("%d\n", temp->data);
    temp=(struct ex*)removeRoot(heap);
    printf("%d\n\n", temp->data);
    for(i=0; i < heap->length; i++){
        printf("%d\n", array[i]->data);
    }
    printf("\n");
    insertNode(heap, temp);
    for(i=0; i < heap->length; i++){
        printf("%d\n", array[i]->data);
    }
    /*
    for (k=0; k<8; k++) {
        for(i=0; i<heap->length; i++){
            printf("%d\n", array[i]->data);
        }
        temp=(struct ex*)removeRoot(heap);
        printf("\n%d\n\n", temp->data);
        free(temp);
    }
    */
    destroyHeap(heap);
    
}
