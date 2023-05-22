// The C Programming Language
// Excercise 1-23 
// Author: Jacob Christensen

#include <stdio.h>

#define MAXLENGTH 10000

int readText(char s[]) {
  
    // Ingest text via stdin, return length of string

    int character;
    int i;
    
    for (i = 0; (character = getchar()) != EOF; i++) {
        printf("%c", character);
        s[i] = character;
    }
    s[i] = '\0';
    return i;
}

void removeComment(char from[], char to[]) {
    /* Remove old style comments like this one */

    char stage[MAXLENGTH];
    int inComment = 0;
    int inQuote = 0;
    int character;
    int fromI;
    int toI;

    while ((character = from[fromI]) != '\0') {
        if (!inComment && character == '/' && from[fromI + 1] == '*' && !inQuote) {
            inComment = 1;
            fromI += 2;
            continue;
        }
        
        else if (inComment && character == '*' && from[fromI + 1] == '/') {
            fromI += 2;
            inComment = 0;
            continue;
        }
        
        else if (inComment) {
            fromI++;
        }

        else {
            stage[toI] = from[fromI];
            toI++;
            fromI++;
        }
    }

    stage[toI] = '\0';
    
    inComment = 0;
    inQuote = 0;
    fromI = 0;
    toI = 0;

    while ((character = stage[fromI]) != '\0') {
        if (!inComment && character == '/' && stage[fromI + 1] == '/' && !inQuote) {
            inComment = 1;
            fromI += 2;
            continue;
        }
        
        else if (inComment && character == '\n') {
            fromI++;
            inComment = 0;
            continue;
        }
        
        else if (inComment) {
            fromI++;
        }

        else {
            to[toI] = stage[fromI];
            toI++;
            fromI++;
        }
    }

    to[toI] = '\0';
}

int main(void) {

    char string[MAXLENGTH];
    char stringNoComment[MAXLENGTH];
    int length = readText(string);

    removeComment(string, stringNoComment);
    printf("%s", stringNoComment);
    return 0;
    /* comment */
}
