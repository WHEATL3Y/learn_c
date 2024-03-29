// The C Programming Language
// Excercise: 4-3
// Author: Jacob Christensen

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXVAL 100
#define MAXOP 100
#define BUFSIZE 100
#define NUMBER '0'

char buf[BUFSIZE];
int bufp = 0;

int sp = 0;
double val[MAXVAL];

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

int getop(char s[]) {

    int i;
    int c;
    int c1;

    while ((s[0] = c = getch()) == ' ' || c == '\t') {
        ;
    }

    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-') {
        return c;
    }

    i = 0;
    if ((c == '-') && (c1 = getch()) == ' ') {
        return '-';
    }
    else if (c == '-' && isdigit(c1)) {
        s[i] = '-';
        ungetch(c1);
        c = c1;
    }

    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch())) {
            ;
        }
    }

    if (c == '.') {
        while (isdigit(s[++i] = c = getch())) {
            ;
        }
    }

    s[i] = '\0';
    if (c != EOF) {
        ungetch(c);
    }

    return NUMBER;

}

void push(double f) {
    
    if (sp < MAXVAL) {
        val[sp++] = f;
    }
    else {
        printf("error: stack full, can't push %g\n", f);
    }

}

double pop(void) {

    if (sp > 0) {
        return val[--sp];
    }
    else {
        printf("error: stack empty\n");
        return 0.0;
    }

}

int main(void) {

    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        /* printf("%d\n", sp); */
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                if ((op2 = pop()) != 0.0) {
                    push(pop() / op2);
                }
                else {
                    printf("error: zero divisor");
                }
                break;
            case '%':
                if ((op2 = pop()) != 0.0) {
                    push((double)((int) pop() % (int) op2));
                }
                else {
                    printf("error: zero divisor");
                }
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
        }
    }

    return 0;

}
