#include <stdio.h>

int main(void) {
    int character;

    character = getchar();
    while (character != EOF) {
        putchar(character);
        character = getchar();
    }
    return 0;
}
