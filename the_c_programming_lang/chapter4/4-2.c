// The C Programming Language
// Excercise: 4-2 
// Author: Jacob Christensen

#include <stdio.h>
#include <ctype.h>
#include <math.h>

double atof(char s[]) {

    double val;
    double power;
    double exponent;
    int i;
    int sign;
    int esign;
    

    for (i = 0; isspace(s[i]); i++) {
        ;
    }

    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-') {
        i++;
    } 

    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
    }

    if (s[i] == '.') {
        i++;
    }

    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }

    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        esign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-') {
            i++;
        }
        for (exponent = 0.0; isdigit(s[i]); i++) {
            exponent = 10.0 * exponent + (s[i] - '0');
        }
    }

    return (sign * val / power) * (pow(10.0, (esign * exponent)));

}

int main(void) {

    char string[] = "123.45e-3";
    printf("%lf\n", atof(string));
    return 0;
}
