// The C Programming Language
// Excercise 1-12 
// Author: Jacob Christensen

#include <stdio.h>

#define SPACE ' '
#define NEWLINE '\n'
#define TAB '\t'

int main(void) {
    // Print each word from input on its own line
    int character;
    int lastCharacterBlank = 0;

    while ((character = getchar()) != EOF) {
        if (character == SPACE || character == NEWLINE || character == TAB) {
            if (lastCharacterBlank) {
                continue;
            }
            lastCharacterBlank = 1;
            printf("\n");
        }
        else {
            lastCharacterBlank = 0;
            putchar(character);
        }
    }
    return 0;
}
