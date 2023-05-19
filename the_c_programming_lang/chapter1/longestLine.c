// The C Programming Language
// Excercise 1-16 
// Author: Jacob Christensen

#include <stdio.h>

#define MAXLINE 1000

int customGetLine(char s[], int maxLine) {

    int character;
    int i;

    for (i = 0; i < maxLine - 1 && (character = getchar()) != EOF && character != '\n'; i++) {
        s[i] = character;
    }
    if (character != '\n' && character != EOF) {
        // We hit the character limit
        s[i] = '\0';
        while((character = getchar()) != EOF && character != '\n') {
            i++;
        }
    }
    if (character == '\n') {
        s[i] = character;
        i++;
        s[i] = '\0';
    }
    else {
        s[i] = '\0';
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
    int maxLength = 0;
    char currentLine[MAXLINE];
    char longestLine[MAXLINE];
    
    while ((currentLength = customGetLine(currentLine, MAXLINE)) > 0) {
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
