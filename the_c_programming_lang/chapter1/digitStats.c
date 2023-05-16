// The C Programming Language
// Excercise
// Author: Jacob Christensen

#include <stdio.h>

int main(void) {

    int digits[10];
    int other = 0;
    int space = 0;
    int newline = 0;
    int tab = 0;
    int character;
    int i;

    while ((character = getchar()) != EOF) {
        if (character >= '0' && character <= '9') {
            digits[character - '0']++;
        }
    }
    printf("Digits: \n");
    for (i = 0; i < 10; i++) {
        printf("%d: %d\n", i, digits[i]);
    }
    return 0;
}
