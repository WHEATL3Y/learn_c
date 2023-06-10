// The C Programming Language
// Excercise: 2-8
// Author: Jacob Christensen

#include <stdio.h>
#include <limits.h>

// Could write function to find u_int size, but this works fine for now
#define UINT_BIT 32

unsigned rightrot(unsigned x, int n) {

    // Return the value of x rotated to the right by n positions

    unsigned nbits = ~(~0 << n) & x;
    x = x >> n;
    nbits = nbits << (UINT_BIT - n);
    return x | nbits;
    
}

int main(void) {

    printf("%u\n", rightrot(255, 7)); 
    return 0;
}
