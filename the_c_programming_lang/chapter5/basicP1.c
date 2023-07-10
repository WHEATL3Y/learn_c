// The C Programming Language
// Excercise: Vasic pointer testing 
// Author: Jacob Christensen

#include <stdio.h>

void changeInt(int*);

void changeInt(int *n) {
    *n = 1234;
}

int main(void) {

    int n = 4321;
    printf("%i\n", n);
    changeInt(&n);
    printf("%i\n", n);
    return 0;
}
