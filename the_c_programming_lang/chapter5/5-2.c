// The C Programming Language
// Excercise: 5-2 
// Author: Jacob Christensen

#include <stdio.h>
#include <ctype.h>
#include <math.h>

int getfloat(double *);

int getfloat(double *pn) {
    
    int c;
    double power;
    double exponent;
    int sign;
    int esign;

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
        *pn = 10.0 * *pn + (c  - '0');
        c = getchar();
    }
   
    if (c == '.') {
        c = getchar();
    }

    for (power = 1.0; isdigit(c);) {
        *pn = 10.0 * *pn + (c - '0');
        power *= 10;
        c = getchar();
    }

    if (c == 'e' || c == 'E') {
        c = getchar();
        esign = (c == '-') ? -1 : 1;
        if (c == '-' || c == '+') {
            c = getchar();
        }
        for (exponent = 0.0; isdigit(c); ) {
            exponent = 10.0 * exponent + (c - '0');
            c = getchar();
        }
    }

    *pn = (sign * *pn / power) * (pow(10.0, (esign * exponent)));

    if (c != EOF) {
        ungetc(c, stdin);
    }

    return c;

}

int main(void) {

    double n;
    int status;

    if ((status = getfloat(&n)) > 0) {
        printf("%lf\n", n);
    }
    else {
        printf("ERROR: %i\n", status);
    }
    
    return 0;
}
