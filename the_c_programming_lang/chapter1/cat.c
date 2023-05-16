// The C Programming Language
// Excercise 1-6, 1-7, 1-9 
// Author: Jacob Christensen

#include <stdio.h>

#define SPACE ' '

int main(void) {
    int character;
    int lastCharacter;
    
    // Exercise 1-7, 1-9
    printf("EOF = %d\n", EOF);
    while ((character = getchar()) != EOF) {
        if (character == SPACE && lastCharacter == SPACE) {
            continue;
        }  

        lastCharacter = character;
        putchar(character);

    }
    
    return 0;
}
