// The C Programming Language
// Excercise: 5-1 
// Author: Jacob Christensen

#include <stdio.h>
#include <ctype.h>

int getint(int *);

int getint(int *pn) {
    
    int c;
    int sign;

    while (isspace(c = getchar())) {
        ;
    }
    
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetc(c, stdin);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if ((c == '+' || c == '-') && isdigit(c = getchar())) {
        ;
    }
    else if (!isdigit(c)) {
        ungetc(c, stdin);
        return 0;
    }

    for (*pn = 0; isdigit(c);) {
        *pn = 10 * *pn + (c  - '0');
        c = getchar();
    }
    
    *pn *= sign;
    if (c != EOF) {
        ungetc(c, stdin);
    }

    return c;

}

int main(void) {

    int n;
    int status;

    if ((status = getint(&n)) > 0) {
        printf("%i\n", n);
    }
    else {
        printf("ERROR: %i\n", status);
    }
    
    return 0;
}
