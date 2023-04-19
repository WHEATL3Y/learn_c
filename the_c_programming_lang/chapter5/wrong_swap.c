#include <stdio.h>

void main(void) {
    int x = 1;
    int y = 2;

    printf("x=%i\ny=%i\n", x, y);
    swap(x, y);
    printf("x=%i\ny=%i\n", x, y);
}

void swap(x, y) {
    int temp;

    temp = x;
    x = y;
    y = temp;
}
