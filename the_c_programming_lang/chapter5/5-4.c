// The C Programming Language
// Excercise: 5-4 
// Author: Jacob Christensen

#include <stdio.h>

int strend(char *, char*);
int length(char *);

int strend(char *s, char *t) {

    int i;
    int sLen = length(s);
    int tLen = length(t);

    s += sLen;
    t += tLen;
    
    for (i = 0;  *s-- == *t--;) {
        i++;
    }

    if (--i == tLen) {
        return 1;
    }
    else {
        return 0;
    }

}

int length(char *s) {

    int i = 0;

    while (*s++) {
        i++;
    }

    return i;

}
int main(void) {

    char *string1 = "12345";
    char *string2 = "445";
    
    printf("%d\n", strend(string1, string2));
    return 0;
}
