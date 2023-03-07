#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

void main() {
    int_conversion();
    float_conversion();
    printf("Reverse\n");
    for_converter();
}

void int_conversion() {
    int f, c;

    f = LOWER;
    while (f <= UPPER) {
        c = 5 * (f - 32) / 9;
        printf("%3d\t%3d\n", f, c);
        f = f + STEP;
    }
}

void float_conversion() {
    float f, c;

    f = LOWER;
    while (f <= UPPER) {
        c = (5.0/9.0) * (f - 32.0);
        printf("%3.0f %6.1f\n", f, c);
        f = f + STEP;
    }
}

void for_converter() {
    int f;

    for (f = UPPER; f >= LOWER; f = f - STEP) {
        printf("%3d %6.1f\n", f, (5.0/9.0) * (f-32));
    }
}