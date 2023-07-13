// The C Programming Language
// Excercise: 5-6 
// Author: Jacob Christensen

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void reverse(char *);
int getL(char *);
int atoi(char *);
void itoa(int n, char *);

void reverse(char *s) {

}

int getL(char *s) {
    
    int c;
    int i;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
        *s++ = c;
    }

    *s++ = '\0';

    return i;
}

int atoi(char *s) {
   
    size_t _;
    int n;
    int sign;

    for (; isspace(*s); ) {
        _ = *s++;
    }
    
    sign = (*s == '-') ? -1 : 1;

    if (*s == '+' || *s == '-') {
        _ = *s++;
    }

    for (n = 0; isdigit(*s); ) {
        n = 10 * n + (*s - '0');
        _ = *s++;
    }

    return sign * n;
}

void itoa(int n, char *s) {

    int sign = n;
    unsigned n1;

    if (n < 0) {
        n1 = (~n) + 1;
    }
    else {
        n1 = n;
    }

    do {
        *s++ = n1 % 10 + '0';
    } while ((n1 /= 10) > 0);

    if (sign < 0) {
        *s++ = '-';
    }

    *s = '\0';
    reverse(s);
}

int main(void) {

    // Test getline and reverse
    char getL_string[1000];

    while ((getL(getL_string))) {
        printf("%s\n", getL_string);
        reverse(getL_string);
        printf("%s\n", getL_string);
    }

    // Test atoi
    char atoi_string[100] = "12345";

    printf("atoi %s => %d\n", atoi_string, atoi(atoi_string));

    // Test itoa
    int itoa_int = 12345;
    char itoa_string[100];

    itoa(itoa_int, itoa_string);
    reverse(itoa_string);
    printf("itoa %d => %s\n", itoa_int, itoa_string);
    return 0;
}
