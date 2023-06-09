// The C Programming Language
// Excercise getbits() 
// Author: Jacob Christensen

#include <stdio.h>

unsigned getbits(unsigned x, int p, int n) {

    // get n bits of x from position p

    printf("(%u >> (%d + 1 - %d)) & ~(~0 << %d)\n", x, p, n, n);
    printf("(%u >> %d) & ~%d\n", x, (p + 1 - n), (~0 << n));
    printf("%u & %d\n", (x >> (p + 1 - n)), (~(~0 << n)));
    return (x >> (p + 1 - n)) & ~(~0 << n);

}
int main(void) {


    printf("%u\n", getbits(255u, 6, 2));
    return 0;
}
