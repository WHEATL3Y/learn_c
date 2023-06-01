// The C Programming Language
// Excercise 2-1 
// Author: Jacob Christensen

#include <stdio.h>

void unsignedInt(void) {

    unsigned int test;
    int length;
    int min = 0;
    unsigned int max;

    for (length = 1, test = 2; test >= 1; length++, test <<= 1) {
        if (test > max) {
            max = test;
        }
    }
    // TODO: This is retuning an answer 1 bit short, fix.
    printf("Unsigned Int:\n\tLength: %d\n\tMin: %d\n\tMax: %u\n", length, min, max);
}

/* int signedInt(void) { */
/*  */
/* } */

int main(void) {

    unsignedInt();
    return 0;
}
