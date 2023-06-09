// The C Programming Language
// Excercise: 2-6
// Author: Jacob Christensen

#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    // Returns x with the n bits that begin at position p to the rightmost n bits of y
    // Leave the other bits unchanged
    // Comments based on x = 255, p = 5, n = 4, y = 170
   
    unsigned xmask;

    // Get y bits
    y = (y & ~(~0u << n)) << (p + 1 - n);   // 00101000 

    // Set mask for x
    xmask = ~(~(~0 << n) << (p + 1 - n));   // 11000011

    // Set all bits to be changed to 0
    x = x & xmask;                          // 11000011

    // Replace with bits from y
    x = x | y;                              // 11101011      
    
    return x;                               // 235
}

int main(void) {

    printf("%u\n", setbits(255, 5, 4, 170));

    return 0;
}
