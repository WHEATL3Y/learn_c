// The C Programming Language
// Excercise 1-16 (Modified for External Variables)
// Author: Jacob Christensen

#include <stdio.h>

#define MAXLINE 1000

int maxLength;
char currentLine[MAXLINE];
char longestLine[MAXLINE];

int customGetLine(void) {

    extern int maxLength;
    extern char currentLine[];
    int character;
    int i;

    for (i = 0; i < maxLength - 1 && (character = getchar()) != EOF && character != '\n'; i++) {
        currentLine[i] = character;
    }
    if (character != '\n' && character != EOF) {
        // We hit the character limit
        currentLine[i] = '\0';
        while((character = getchar()) != EOF && character != '\n') {
            i++;
        }
    }
    if (character == '\n') {
        currentLine[i] = character;
        i++;
        currentLine[i] = '\0';
    }
    else {
        currentLine[i] = '\0';
    }
    
    return i;
}

void customCopy(char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0') {
        i++;
    }
}

int main(void) {

    int currentLength;
    extern int maxLength;
    extern char currentLine[MAXLINE];
    extern char longestLine[MAXLINE];
    
    maxLength = 0;
    while ((currentLength = customGetLine()) > 0) {
        if (currentLength > maxLength) {
            maxLength = currentLength;
            customCopy(longestLine, currentLine);
        }
    }

    if (maxLength > 0) {
        printf("Longest Line (%d):\n%s\n", maxLength, longestLine);
    }

    return 0;
}
