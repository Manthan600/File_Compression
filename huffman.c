#include "heap.h"
#include "huffman.h"

struct Node* buildHuffmanTree(char arr[], int freq[],
                              int unique_size)
{
    struct Node *l, *r, *top;
    while (!isSizeOne(Min_Heap)) {
        l = extractMinFromMin_Heap(Min_Heap);
        r = extractMinFromMin_Heap(Min_Heap);
        top = newNode('$', l->freq + r->freq);
        top->l = l;
        top->r = r;
        insertIntoMin_Heap(Min_Heap, top);
    }
    return extractMinFromMin_Heap(Min_Heap);
}