// The C Programming Language
// Excercise: 4-9
// Author: Jacob Christensen

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXVAL 100
#define MAXOP 100
#define BUFSIZE 100
#define NUMBER '0'
#define SETVAR '8'
#define GETVAR '9'

int buf[BUFSIZE];
int bufp = 0;

int sp = 0;
double val[MAXVAL];
double var[26];
double last;

void clear(void) {
    sp = 0;
}

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

    if (c >= 'A' && c <= 'Z') {
        return SETVAR;
    }

    if (c >= 'a' && c <= 'z') {
        return GETVAR;
    }

    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-') {
        return c;
    }

    i = 0;
    if ((c == '-') && ((c1 = getch()) == ' ' || c1 == '\n')) {
        ungetch(c1);
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

void swap(void) {
    // Swap the top two elements on the stack

    int op1;
    int op2;

    if (sp >= 1) {
        op1 = pop();
        op2 = pop();
        push(op1);
        push(op2);
    }
    else {
        printf("error: not enough values in stack\n");
    }
}

double top(void) {

    // Return the top n elements from the stack, don't modify the stack.

    if (sp > 0) {
        return val[sp - 1];
    }
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int main(void) {

    int type;
    double op2;
    double op1;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        /* printf("%d\n", sp); */
        switch (type) {
            case SETVAR:
                // Set the variable to top value of the stack
                var[s[0] - 'A'] = top();
                break;
            case GETVAR:
                // Replace a variable with it's value
                push(var[s[0] - 'a']);
                break;
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
                swap();
                push(pop() - pop());
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
            case '^':
                // pow
                push(pow(pop(), pop()));
                break;
            case '\"': 
                // exp
                push(exp(pop()));
                break;
            case '~':
                // sin
                push(sin(pop()));
                break;
            case '?':
                // Print top value
                printf("%lf\n", top());
                break;
            case ':':
                // Duplicate top value
                push((top()));
                break;
            case '$':
                // Push last printed value to the stack
                push(last);
                break;
            case '_':
                // Clear stack
                clear();
                break;
            case '\n':
                last = op2 = pop();
                printf("\t%.8g\n", op2);
                break;
        }
    }

    return 0;

}
