// The C Programming Language
// Excercise: 2-9
// Author: Jacob Christensen

#include <stdio.h>

int bitcount(unsigned x) {
    // Returns the number of 1 bits in x
    
    int i;

    for (i = 0; x > 0; x &= (x - 1), i++) {
        ;
    }

    return i;
}
int main(void) {

    printf("%u\n", bitcount(255));
    return 0;
}
