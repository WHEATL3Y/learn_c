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
        s[i] = character;
    }
    s[i] = '\0';
    return i;
}

void removeComment(char from[], char to[]) {
    /* Remove old style comments like this one */
    /* This is a "quote in a comment", 'so is this' */
    char stage[MAXLENGTH];
    int inComment = 0;
    int inQuote = 0;
    int quoteDelimeter;
    int inLine = 0;
    int column = 0;
    int character;
    int fromI = 0;
    int toI = 0;

    while ((character = from[fromI]) != '\0') {
        /*if (!inComment && (character == '"' || character == '\'')) {
            if (inQuote) {
                inQuote = 0;
            }
            else {
                inQuote = 1;
            }
        }*/
        if (!inComment && (character == '\"' || character == '\'')) {
            if (inQuote && character == quoteDelimeter && from[fromI - 1] != 92) {
                inQuote = 0;
                /* stage[toI++] = 'o'; */
            }
            else if (inQuote && character == quoteDelimeter && from[fromI - 1] == 92 && from[fromI - 2] == 92) {
                inQuote = 0;
            }
            else if (inQuote && quoteDelimeter != character) {
                ;
            }
            else {
                quoteDelimeter = character;
                /* stage[toI++] = 'i'; */
                inQuote = 1;
            }
        }
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
            continue;
        }

        stage[toI] = from[fromI];
        toI++;
        fromI++;
    }

    stage[toI] = '\0';
    
    inComment = 0;
    inQuote = 0;
    fromI = 0;
    toI = 0;

    while ((character = stage[fromI]) != '\0') {
        column++;
        if (character == '\n') {
            column = 0;
        }
        if (!inComment && (character == '\"' || character == '\'')) {
            if (inQuote && character == quoteDelimeter && from[fromI - 1] != '\\') {
                inQuote = 0;
            }
            else if (inQuote && character == quoteDelimeter && from[fromI - 1] == 92 && from[fromI - 2] == 92) {
                inQuote = 0;
            }
            else if (inQuote && quoteDelimeter != character) {
                ;
            }
            else {
                quoteDelimeter = character;
                inQuote = 1;
            }
        }
        if (!inComment && character == '/' && stage[fromI + 1] == '/' && !inQuote) {
            
            if (column != 1) {
                inLine = 1;
            }
            else {
                inLine = 0;
            }

            inComment = 1;
            fromI += 2;
            continue;
        }
        else if (inComment && character == '\n') {
            fromI++;
            inComment = 0;

            if (inLine) {
                to[toI] = '\n';
                toI++;
            }

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
