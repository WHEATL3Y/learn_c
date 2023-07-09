// The C Programming Language
// Excercise: 5-3 
// Author: Jacob Christensen

#include <stdio.h>

int length(char *);
char *cat(char *, char *);

int length(char *s) {

    int i;

    while ((*s++) != 0) {
        i++;
    }

    return i;

}

char *cat(char *s, char *t) {
    
    s += length(s);
    while ((*s++ = *t++)) {
        ;
    }

    return s;
}

int main(void) {

    char *string1 = "12345";
    char *string2 = "67890";
    printf("%s\n", cat(string1, string2));
    return 0;
}
