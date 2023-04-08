#include <stdio.h>
#include <time.h>

void main () {
	clock_t start;
	start = clock();
	printf("%li", (long)start);
}
