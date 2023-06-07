// The C Programming Language
// Excercise 2-5 
// Author: Jacob Christensen

#include <stdio.h>

int findChar(char s1[], char s2[]) {

    int i1;
    int i2;
    int c1;
    int c2;

    for (i1 = 0; (c1 = s1[i1++]) != '\0'; ) {
        for (i2 = 0; (c2 = s2[i2++]) != '\0'; ) {
            if (c1 == c2) {
                return --i1;
            }
        }
    }
    
    return -1;
}
    
int main(void) {

    char string1[] = "This is a test string";
    char string2[] = "q";

    printf("%d\n", findChar(string1, string2));

    return 0;
}
