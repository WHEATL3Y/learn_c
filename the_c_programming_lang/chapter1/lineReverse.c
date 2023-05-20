// The C Programming Language
// Excercise 1-19 
// Author: Jacob Christensen

#include <stdio.h>

#define MAXLENGTH 10000

int strLength(char string[]) {

    int i;
    for (i = 0; string[i] != '\0'; i++) {
        ;
    }

    return i;
}

void copy(char to[], char from[]) {

    int i;

    for (i = 0; (to[i] = from[i]) != '\0'; i++) {
        ;
    }
}

void reverse(char string[]) {

    int length = strLength(string);
    char newString[length];
    int i;
    int j;
    int character;

    for (i = 0, j = length - 1; j >= 0; j--, i++) {
        newString[j] = string[i];
    }

    newString[i] = '\0';
    copy(string, newString);
}

int getLine(char string[], int limit) {

    int character;
    int i;

    for (i = 0; (character = getchar()) != EOF && character != '\n' && i < limit; i++) {
        string[i] = character;
    }

    string[i] = '\0';

    if (character == '\n') {
        return i + 1;
    }
    else {
        return i;
    }
}

int main(void) {

    char line[MAXLENGTH];
    int length;

    while ((length = getLine(line, MAXLENGTH)) != 0) {
        reverse(line);
        printf("%s\n", line);
    }

    return 0;
}
