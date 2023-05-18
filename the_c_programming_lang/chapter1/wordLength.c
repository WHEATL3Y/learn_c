// The C Programming Language
// Excercise 1-13 
// Author: Jacob Christensen

#include <stdio.h>

int main(void) {

    int wordLengths[10];
    int length = 0;
    int character;
    int i;
    int j;

    while((character = getchar()) != EOF) {
        if (character == '\n' || character == ' ' || character ==  '\t') {
            if (length == 0) {
                length = 0;
                continue;
            }
            else if (length > 10) {
                wordLengths[9]++;
            }
            else {
                wordLengths[length - 1]++;
            }
            length = 0; 
        }
        else {
            length++;
        }
    }

    printf("'=' = 10 occurences\n");
    for (i = 0; i < 9; i++) {
        printf("%d  : ", i + 1);
        for (j = wordLengths[i] / 10; j > 0; j--) {
            printf("=");
        }
        printf("\n");
    }
    printf("10+: ");
    for (j = wordLengths[9] / 10; j > 0; j--) {
        printf("=");
    }
    printf("\n");
    return 0;
}
