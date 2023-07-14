// Effective C
// Chapter 1: safehello.c
// Author Jacob Christensen

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    if ((puts("Hello World!")) == EOF) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
