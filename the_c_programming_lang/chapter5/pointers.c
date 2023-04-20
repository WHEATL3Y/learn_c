#include <stdio.h>

void main(void) {
    // Create an array of 10 pointers
    int *a[10];
     
    // Create a two dimensional array
    int b[10][10];
     
    // Print a pointer
    char printPointer = 1;
    printf("%p", &printPointer);
}

