// The C Programming Language
// Excercise: itoa.c 
// Author: Jacob Christensen

#include <stdio.h>

#define MAX_LENGTH 1000

int length(char s[]) {

    int i;

    for (i = 0; s[i++] != '\0'; ) {
        ;
    }

    return i - 2;

}

void reverse(char s[]) {

    int i;
    int j = length(s); 
    char temp;

    for (i = 0; i < j; i++, j--) {
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
    }
}

void itoa(int n, char s[]) {

    int i;
    int sign = n;
    unsigned int n1 = (~n) + 1; 
    i = 0;

    do {
        s[i++] = n1 % 10 + '0';
    } while ((n1 /= 10) > 0);

    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

int main(void) {

    int n = -2147;
    char string[MAX_LENGTH];
    itoa(n, string);

    printf("%s\n", string);
    return 0;
}
