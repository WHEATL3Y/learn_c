#include <stdio.h>

void main(void) {
    int x = 1;
    int y = 2;

    printf("x=%i\ny=%i\n", x, y);
    swap(&x, &y);
    printf("x=%i\ny=%i\n", x, y);
}

void swap(int *a, int *b) {
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
