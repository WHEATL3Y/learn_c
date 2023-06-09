// The C Programming Language
// Chapter 2: 2-6
// Author: Jacob Christensen

#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    // Returns x with the n bits that begin at position p to the rightmost n bits of y
    // Leave the other bits unchanged

    // Get y bits
    y = y & ~(~0u << n);

    // Set mask for x
    unsigned xmask = ~0;
    


     return 0;
}

int main(void) {

    setbits(1, 1, 4, 170);
    return 0;
}
