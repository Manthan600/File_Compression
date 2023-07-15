#include "heap.h"
#include "huffman.h"
#include <stdio.h>
#include <stdlib.h>

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




int* frequency_table_creator(char paragraph[]){
    printf("in freq\n");
    int* frequency = (int*)calloc(256,sizeof(int));
    int i=0;
    while(paragraph[i]!='\0'){
        // printf("in while %d\n",i);
        
        int k = paragraph[i];
        frequency[k]++;
        i++;
    }
    printf("done freq\n");
    return frequency;
}


node* create_node(char i , int freq){
    node * nn = (node*)malloc(sizeof(node));
    if (!nn) {
        printf("Memeory not allocated to node !!!");
        return NULL;
    }
    nn->ch =i;
    nn->freq =freq;
    return nn;
}

heap* create_min_heap(int freq[]){
    heap* h =(heap*)malloc(sizeof(heap));
    if (!h){
        printf("Memeory not allocated to heap !!!");
        return NULL;
    }
    initHeap(h,1);
    // printf("Init done\n");
    for(int i=0; i<256; i++){
        if (freq[i]!=0){
            // printf("%d\t",i);
            node*nn=create_node(i,freq[i]); 
            insertHeap(h,nn);
        }
    }
    printf("\n");
    return h;
}
