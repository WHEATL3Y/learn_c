// The C Programming Language
// Excercise: 4-8
// Author: Jacob Christensen

#include <stdio.h>
#include <string.h>

char buf = 0;

int getch(void) {

    int c;
    if ((c = buf )) {
        buf = 0;
    }
    return (c) ? c : getchar();

}

void ungetch(int c) {

    buf = c;

}

int main(void) {

    int i;
    int c;
    char s[100];

    for (i = 0; i < 5;) {
        c = getch();
        s[i++] = c;
    }

    i--;
    ungetch(c);

    for (; (c = getch()) != EOF;) {
        s[i++] = c;
    }

    printf("%s\n", s);
    return 0;

}
