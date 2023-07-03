// The C Programming Language
// Excercise: 4-12
// Author: Jacob Christensen

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

int length(char s[]) {

    int i;

    for (i = 0; s[i++] != '\0'; ) {
        ;
    }

    return i - 1;

}

void reverse(char s[]) {

    int i;
    int j = length(s) - 1; 
    char temp;

    for (i = 0; i < j; i++, j--) {
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
    }
}

void itoa(int n, char s[]) {

    static int i = 0;
    unsigned n1;

    if (n < 0) {
        n1 = (~n) + 1; 
        s[i++] = '-';
    } 
    else {
        n1 = n;
    }

    if (n1 / 10) {
        itoa((int) (n1 / 10), s);
    }

    s[i++] = n1 % 10 + '0';
    s[i] = '\0';

}

int main(void) {

    int n = 214320937;
    char string[MAX_LENGTH];
    itoa(n, string);

    printf("%s\n", string);
    return 0;
}
