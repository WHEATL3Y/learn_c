// The C Programming Language
// Excercise 1-20 
// Author: Jacob Christensen

#include <stdio.h>

#define TABWIDTH 4
#define MAXLENGTH 1000

int main(void) {
 
    int character;
    int column;
    int numSpaces;
    int i;
    char s[MAXLENGTH];

    // TODO: This would probably be less confusing as a while loop, with better control over i, and column interation
    for (i = 0, column = 0; (character = getchar()) != EOF && i < MAXLENGTH - 1; i++, column++) {
        if (character == '\t') {
            numSpaces = TABWIDTH - (column % TABWIDTH);
            for (; numSpaces > 0; numSpaces--) {
                s[i] = ' ';
                i++;
                column++;
            }
            // Compensate for iteration in loop control
            i--;    
            column--;
        }
        else {
            s[i] = character;
            if (character == '\n') {
                // Compensate for iteration in loop control
                column = -1; 
            }
        }
    }
    s[i] = '\0';
    printf("%s", s);
    return 0;
}
