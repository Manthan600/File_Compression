#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

struct Min_Heap *createAndBuildMin_Heap(char arr[], int freq[], int unique_size)
{
    int i;

    // Initializing heap
    struct Min_Heap *Min_Heap = (struct Min_Heap *)malloc(sizeof(struct Min_Heap));
    Min_Heap->size = unique_size;
    Min_Heap->array = (struct Node **)malloc(
        Min_Heap->size * sizeof(struct Node *));

    // Initializing the array of pointers in minheap.
    // Pointers pointing to new nodes of character
    // and their frequency
    for (i = 0; i < unique_size; ++i)
    {

        // newNode is a function
        // to initialize new node
        Min_Heap->array[i] = newNode(arr[i], freq[i]);
    }

    int n = Min_Heap->size - 1;
    for (i = (n - 1) / 2; i >= 0; --i)
    {

        // Standard function for Heap creation
        Heapify(Min_Heap, i);
    }

    return Min_Heap;
}