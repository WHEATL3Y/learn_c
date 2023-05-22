// The C Programming Language
// Excercise 1-21 
// Author: Jacob Christensen

#include <stdio.h>

#define TABSTOP 4
#define MAXLENGTH 1000

int main(void) {

    char string[MAXLENGTH];
    int character;
    int i = 0;
    int spaces = 0;
    int tabs = 0;
    int column = 0;

    while ((character = getchar()) != EOF) {
        if (character == ' ') {
            spaces++;
        } 
        else if (spaces > 0) {
            if (spaces == 1) {
                string[i] = ' ';
                i++;
            } 
            else if (spaces < 4) {
                string[i] = '\t';
                i++;
            } 
            else {
                tabs = spaces / 4;
                if (spaces % 4) {
                    tabs++;
                }
                for (; tabs > 0; tabs--) {
                    string[i] = '\t';
                    i++;
                }
            }
            string[i] = character;
            i++;
            spaces = 0;
        } 
        else {
            string[i] = character;
            i++;
        }
    }
    string[i] = '\0';
    printf("%s", string);

    return 0;
}
