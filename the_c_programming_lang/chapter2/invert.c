// The C Programming Language
// Excercise: 2-6
// Author: Jacob Christensen

#include <stdio.h>

unsigned invert(unsigned x, int p, int n) {
    // Returns x with the n bits that begin at p inverted
   
    return ~(~(~0 << n) << (p + 1 - n) & x) & (~(~0 << n) << (p + 1 - n) | x);
}
int main(void) {

    printf("%u\n", invert(170, 4, 3));
    printf("%u\n", invert(1234, 7, 4));
    return 0;
}
