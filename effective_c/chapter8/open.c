// Effective C
// Chapter 8: Opening files 
// Author Jacob Christensen

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int c;
    FILE *file = fopen("test.txt", "r");

    for (; (c = getc(file)) != EOF; ) {
        putchar(c);
    }
    return EXIT_SUCCESS;
}
