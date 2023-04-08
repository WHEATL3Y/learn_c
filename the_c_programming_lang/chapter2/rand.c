#include <stdio.h>
#include <time.h>

unsigned long int next;

int rand(void) {
        next = next * 1103515245 + 12345;
        return (unsigned int) (next/65536) % 10;
}

void srand(unsigned int seed) {
        next = seed;
}

void main () {
	clock_t t;
	t = clock();
	srand((unsigned int) t);
	printf("Generating Random Numbers\n");
	int i, n;
        for (i = 0; i < 10; i++) {
		n = rand();
		printf("Random Number %d: %i\n", i, n);
        }
}
