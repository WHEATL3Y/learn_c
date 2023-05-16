// The C Programming Language
// Excercise 1-8
// Author: Jacob Christensen

#include <stdio.h>

#define NEWLINE '\n'
#define SPACE ' '
#define TAB '\t'
#define INWORD 1
#define OUTWORD 0

int main(void) {
    int character;
    int characterCount = 0;
    int lineCount = 0;
    int spaceCount = 0;
    int tabCount = 0;
    int wordCount = 0;
    int state = INWORD;

    // While loop
    /* while (getchar() != EOF) { */
    /*     characterCount++; */
    /* } */
    
    // For loop method requires no loop body
    /* for (characterCount; getchar() != EOF; characterCount++) { */
    /*     ; */
    /* } */
   
    while ((character = getchar()) != EOF) {
        characterCount++;
        if (character == NEWLINE) {
            lineCount++;
            state = OUTWORD;
        }
        else if (character == SPACE) {
            spaceCount++;
            state = OUTWORD;
        }
        else if (character == TAB) {
            tabCount++;
            state = OUTWORD;
        }
        else if (!state) {
            wordCount++;
            state = INWORD;
        }
    }
    printf("Characters: %d\n", characterCount); 
    printf("Words: %d\n", wordCount);
    printf("Lines: %d\n", lineCount);
    printf("Spaces: %d\n", spaceCount);
    printf("Tabs: %d\n", tabCount);
    return 0;
}
