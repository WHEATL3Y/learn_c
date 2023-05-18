// The C Programming Language
// Excercise 1-14 
// Author: Jacob Christensen

#include <stdio.h>

int main(void) {
    // ASCII 0-9 = 48-57
    // ASCII A-Z = 65-90
    // ASCII a-z = 97-122 (+ 32)
    
    int character;
    int i;
    int j;
    // 0-9 = 0-9
    // 10-36 = a-z
    int digits[10] = {0};
    int characters[26] = {0};
    int whitespace = 0;
    int other = 0;

    while ((character = getchar()) != EOF) {
        if (character >= '0' && character <= '9') {
            digits[character - '0']++;
        } 
        else if (character >= 'a' && character <= 'z' || character >= 'A' && character <= 'Z') {
            if (character >= 97) {
                character -= 32;
            }
            characters[character - 'A']++;
        }
        else if (character == '\n' || character == ' ' || character == '\t') {
            whitespace++;
        }
        else {
            other++;
        }
    }

    for (i = 0; i < 10; i++) {
        printf("%d: ", i);
        for (j = digits[i] / 10; j > 0; j--) {
            printf("=");
        }
        printf("\n"); 
    }
    
    for (i = 0; i < 26; i++) {
        printf("%c: ", i + 65);
        for (j = characters[i] / 10; j > 0; j--) {
            printf("=");
        }
        printf("\n");
    }
    return 0;
}
