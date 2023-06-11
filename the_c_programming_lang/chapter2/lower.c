// The C Programming Language
// Excercise: 2-10
// Author: Jacob Christensen

#include <stdio.h>

void lower(char s[]) {

    int i;
    int c;

    for (i = 0; (c = s[i]) != '\0'; i++) {
        s[i] = (c >= 65 && c <= 90) ? c + 32 : c;
    }
}
int main(void) {

    char string[] = "This is a String with CAPS";
    lower(string); 
    printf("%s\n", string);
    return 0;
}
