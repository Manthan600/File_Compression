#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 1000
#include "huffman.h"



int main(int argc, char const *argv[]) {
    FILE *file;
    char filename[100];
    char paragraph[MAX_LENGTH];
    char ch;
    int i = 0;

    // printf("Enter the filename: ");
    // scanf("%s", filename);

    // Open the file in read mode
    file = fopen(argv[1], "r");

    // Check if the file was opened successfully
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    // Read the characters from the file and store them in the paragraph array
    while ((ch = fgetc(file)) != EOF && i < MAX_LENGTH - 1) {
        paragraph[i++] = ch;
    }

    // Null-terminate the paragraph
    paragraph[i] = '\0';

    // Close the file
    fclose(file);

    // Print the paragraph
    printf("Paragraph:\n%s\n", paragraph);

    int* freq = frequency_table_creator(paragraph);
    for(int i=0;i<256;i++){
        if (freq[i]!=0)
            printf("%d\t%d\n", freq[i],i);
    }

    heap * h =create_min_heap(freq);
    printHeap(h);

    


    return 0;
}



