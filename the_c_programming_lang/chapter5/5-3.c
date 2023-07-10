// The C Programming Language
// Excercise: 5-3 
// Author: Jacob Christensen

#include <stdio.h>

int length(char *);
void cat(char *, char *);

int length(char *s) {

    int i;

    while (*s++) {
        i++;
    }

    return i - 1;

}

void cat(char *s, char *t) {
  
    int len = length(s);
    s += len;
    while ((*s = *t) != '\0') {
        ++s;
        ++t;
    }

}

int main(void) {

    char string1[100] = "12345";
    char string2[100] = "67890";
    cat(string1, string2);
    printf("%s\n", string1);
    return 0;
}
