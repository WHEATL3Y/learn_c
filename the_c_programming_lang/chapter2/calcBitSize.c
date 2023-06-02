// The C Programming Language
// Excercise 2-1 
// Author: Jacob Christensen

#include <stdio.h>

void unsignedInt(void) {

    unsigned int uint;
    unsigned int mask;
    int length;

    for (uint = 1, mask = 1, length = 0; mask != 0; mask <<= 1, uint = uint | mask, length++) {
        ;
    }
    printf("Unsigned Int\n\tLength: %u\n\tMin: 0\n\tMax: %u\n", length, uint);
}

/* void signedInt(void) { */
/*  */
/*     int sint; */
/*     int mask; */
/*     int length; */
/*  */
/*     for (sint = 1, mask = 1, length = 0; mask > 0; mask <<= 1, sint = sint | mask, length++) { */
/*         printf("%d\n", sint); */
/*     } */
/*      */
/*     printf("Signed Int\n\tLength: %d\n\tMin: %d\n\tMax: %d\n", length, sint, sint >> 3); */
/* } */

int main(void) {

    unsignedInt();
    /* signedInt(); */
    return 0;
}
