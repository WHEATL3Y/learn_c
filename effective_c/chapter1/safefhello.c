// Effective C
// Chapter 1: safefhello.c
// Author Jacob Christensen

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    if ((printf("%s\n", "Hello World!")) < 0) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
