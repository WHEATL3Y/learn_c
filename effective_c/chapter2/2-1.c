// Effective C
// Chapter 2: 2-1 
// Author Jacob Christensen

#include <stdio.h>
#include <stdlib.h>

static unsigned int counter = 0;

void increment(void);
int retrieve(void);

void increment(void) {

    printf("%u\n", counter++);

}

int retrieve(void) {

    return counter;

}

int main(void) {

    int i;

    for (i = 0; i < 5; i++) {
        printf("%u\n", retrieve());
        increment();
    }
   
    return EXIT_SUCCESS;
}
