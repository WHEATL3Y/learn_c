// The C Programming Language
// Excercise 1-17 
// Author: Jacob Christensen

#include <stdio.h>

#define THRESHOLD 80

int getLongLines(int threshold) {
    // Print any lines longer than threshold

    int character;
    int i;
    char string[threshold + 1];

    for (i = 0; (character = getchar()) != '\n' && character != EOF && i <= threshold; ++i) {
        string[i] = character; 
    }
    if (character != EOF && character != '\n') {
        string[i + 1] = '\0';
        printf("%s", string);
        while((character = getchar()) != EOF && character != '\n') {
            i++;
            putchar(character);
        }
        printf("\n");
    }
    if (character == '\n')
        return ++i;
    if (character == EOF) {
        return 0;
    }

    return i;
}

int main(void) {
    
    int length;

    while ((length = getLongLines(THRESHOLD)) > 0) {
        ;
    }

    return 0;
}
