// The C Programming Language
// Excercise: 5-5 
// Author: Jacob Christensen

#include <stdio.h>
#include <string.h>

void copy(char *, char *, int);
void cat(char *, char *, int);
int cmp(char *, char *, int);

void copy(char *s, char *t, int n) {

    int i;
    
    for (i = 0; i < n; i++) {
        *t++ = *s++;
    }

    *t = '\0';

}

void cat(char *s, char *t, int n) {

    int i;
    int len = strlen(s);

    s += len;
    for (i = 0; (*s = *t) != '\0' && i < n; i++, s++, t++) {
        ;
    }

    *s = '\0';

}

int cmp(char *s, char *t, int n) {
    
    int i;

    for (i = 0; (*s++ == *t++) != '\0' && i < n; i++) {
        ;
    }

    if (i == n) {
        return 1;
    }
    else {
        return 0;
    }

}
int main(void) {

    char CP_string1[10] = "12345";
    char CP_string2[10];

    copy(CP_string1, CP_string2, 3); 
    printf("%s\n", CP_string2);

    char CT_string1[10] = "12345";
    char CT_string2[10] = "67890";

    cat(CT_string1, CT_string2, 3);
    printf("%s\n", CT_string1);

    char CM_string1[10] = "12345";
    char CM_string2[10] = "12365";
    printf("%d\n", cmp(CM_string1, CM_string2, 3));

    return 0;
    
}
