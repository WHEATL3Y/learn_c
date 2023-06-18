// The C Programming Language
// Excercise: 4-1 
// Author: Jacob Christensen

#include <stdio.h>
#include <string.h>

int strindex(char s[], char t[]) {
    
    int i = strlen(s) - 1;
    int j;

    for (; i >= 0; ) {
        for (j = strlen(t) - 1; s[i--] == t[j--];) {
            if (j == 0) {
                return i;
            }
        }
    }
    return -1;
}

int main(void) {

    char string[] = "This is a test test test";
    char string1[] = "test";
    
    printf("%d\n", strindex(string, string1));
    return 0;
}
