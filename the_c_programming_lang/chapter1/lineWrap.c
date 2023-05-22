// The C Programming Language
// Excercise 1-22 
// Author: Jacob Christensen

#include <stdio.h>

#define MAXLENGTH 10000
#define WIDTH 80

void printSlice(int start, int end, char s[]) {
    
    char toPrint[(end - start) + 1];
    int i;

    for (i = 0; start < end; i++, start++) {
        toPrint[i] = s[start];
    }
   
    toPrint[i] = '\n';
    toPrint[i + 1] = '\0';
    printf("%s", toPrint);
    return;
}

int main(void) {
    char string[MAXLENGTH];
    int character;
    int i;
    int column;
    int lineStart;

    for (i = 0; (character = getchar()) != EOF; i++) {
        string[i] = character;
    }

    string[i] = '\0';

    column = WIDTH;
    lineStart = 0;

    while ((character = string[column]) != '\0') {
        if (character == ' ') {
            printSlice(lineStart, column, string);
            lineStart = column + 1;
            column += WIDTH;
        }
        else if (character == '\n') {
            printSlice(lineStart, column - 1, string);
            lineStart = column + 1;
            column += WIDTH;
        }
        else if (lineStart == column) {
            printSlice(lineStart, lineStart + WIDTH, string);
            lineStart += WIDTH;
            column += WIDTH * 2;
        }
        else {
            column--;
        }
    }
    return 0;
}
