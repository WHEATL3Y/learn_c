// The C Programming Language
// Excercise: Pointer Arithmetic 
// Author: Jacob Christensen

#include <stdio.h>

int main(void) {

    int numbers[] = {1, 2, 3, 4, 5};
    int *n = numbers;

    for (;;) {
        printf("%d\n", *n);
        n++;
    }
    return 0;
} 

