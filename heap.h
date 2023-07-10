// Structure for tree nodes
struct Node {
    char character;
    int freq;
    struct Node *l, *r;
};
 
// Structure for min heap
struct Min_Heap {
    int size;
    struct Node** array;
};