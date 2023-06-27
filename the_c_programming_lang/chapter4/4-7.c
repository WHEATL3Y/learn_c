// The C Programming Language
// Excercise: 4-7
// Author: Jacob Christensen

#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {

    return (bufp > 0) ? buf[--bufp] : getchar();

}

void ungetch(int c) {
    
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    }
    else {
        buf[bufp++] = c;
    }
}

void reverse(char s[]) {

    // reverse a string in place

    int i;
    int j;
    char t;

    for (i = 0, j = strlen(s) - 1; i < j;) {
        t = s[i];
        s[i++] = s[j];
        s[j--] = t;
    }

}

void ungets(char s[]) {

    int i;
    int c;

    reverse(s);

    for (i = 0; (c = s[i++]) != '\0';) {
        ungetch(c);
    }
}

int main(void) {

    int i;
    char s[BUFSIZE];

    for (i = 0; i < 5; i++) {
        s[i] = getch();
    }

    s[i] = '\0';

    ungets(s);

    for (i = 0; (s[i] = getch()) != EOF; i++) {
        ;
    }

    printf("%s\n", s);

    return 0;

}
