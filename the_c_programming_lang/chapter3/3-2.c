// The C Programming Language
// Excercise: 3-2
// Author: Jacob Christensen

#include <stdio.h>
#include <string.h>

void escape(char s[], char t[]) {
    // Replace characters tab and newline into visible escape sequences
    // /t, /n

    int i;
    int j;
    int c;

    for (i = 0, j = 0; (c = s[i]) != '\0'; i++, j++) {
        switch(c) {
            case '\n': t[j++] = '\\'; t[j] = 'n'; break;
            case '\t': t[j++] = '\\'; t[j] = 't'; break;
            default: t[j] = c; break;
        }
    }
    
    t[j] = '\0';

}

void unescape(char s[], char t[]) {
    // Replace escaped whitespace characters with the real ones
    
    int i;
    int j;
    int c;

    for (i = 0, j = 0; (c = s[i]) != '\0'; i++, j++) {
        if (c == '\\') {
            switch(s[++i]) {
                case 'n': t[j] = '\n'; break;
                case 't': t[j] = '\t'; break;
                default: break;
            }
        }
        else {
            t[j] = c;
        }
    }
    
    t[j] = '\0';

}

int main(void) {

    char string1[] = "\tThis is a string with\nmultiple lines\tand some tabs";
    char string2[strlen(string1) + 1];
    char string3[strlen(string1) + 1];

    escape(string1, string2);
    unescape(string2, string3);
    printf("%s\n", string1);
    printf("%s\n", string2);
    printf("%s\n", string3);
    return 0;
}
