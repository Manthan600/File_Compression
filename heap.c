#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

void initHeap(heap *h, int size)
{
    h->arr = (node **)malloc(sizeof(node *) * size);

    if (!h->arr)
    {
        printf("Memory is not allocated !!! \n");
        return;
    }

    h->size = size;
    h->rare = -1;
    return;
}

void insertHeap(heap *h, node *val)
{

    if (h->size <= h->rare + 1)
    {

        h->size *= 2;
        // printf("new size %d\n",h->size);
        h->arr = realloc(h->arr, sizeof(node *) * h->size);
        if (h->arr == NULL)
        {
            printf("Memory is not allocated !!! \n");
            return;
        }
    }

    h->rare++;
    h->arr[h->rare] = val;

    int curr = h->rare;
    int parent = (curr - 1) / 2;

    while (h->arr[curr]->freq < h->arr[parent]->freq)
    {
        // printf("in while\n");
        node *temp = h->arr[curr];
        h->arr[curr] = h->arr[parent];
        h->arr[parent] = temp;

        curr = parent;
        parent = (curr - 1) / 2;
    }
    // printf("out while\n");
    return;
}

void heapify(node **arr, int start, int size)
{

    int curr = start;
    int left = 2 * start + 1;
    int right = 2 * start + 2;

    if (left < size && arr[curr]->freq > arr[left]->freq)
    {
        curr = left;
    }

    if (right < size && arr[curr]->freq > arr[right]->freq)
    {
        curr = right;
    }

    if (start != curr)
    {
        node *temp = arr[start];
        arr[start] = arr[curr];
        arr[curr] = temp;

        heapify(arr, curr, size);
    }

    return;
}

node *dequeueHeap(heap *h)
{
    if (!isEmptyHeap(*h))
    {
        return NULL;
    }

    node *temp = h->arr[0];
    h->arr[0] = h->arr[h->rare];

    h->rare--;

    heapify(h->arr, 0, h->rare);

    return temp;
}

int isEmptyHeap(heap h)
{
    h.rare == -1;
}

void printHeap(heap *h)
{
    printf("\n");
    for (int i = 0; i <= h->rare; i++)
    {
        printf("| %c %d | ", h->arr[i]->ch, h->arr[i]->freq);
    }
    printf("\n");
}