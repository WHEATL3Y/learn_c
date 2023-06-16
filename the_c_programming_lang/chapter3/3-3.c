// The C Programming Language
// Excercise: 3-3
// Author: Jacob Christensen

#include <stdio.h>

void singleExpand(char begin, char end, char s[]) {

    int i;

    for (i = 0; begin <= end; i++, begin++) {
       s[i] = begin; 
    }

    s[i] = '\0';

}

void stringConcat(char s1[], char s2[]) {
    // Append the contents of s2 to the end of s1
    // Skip consecutive duplicates

    int i;
    int j;

    for (i = 0; s1[i] != '\0'; i++) {
        ;
    }

    for (j = 0; s2[j] != '\0';) {
        if (s1[i - 1] == s2[j]) {
            j++;
        }
        else {
            s1[i++] = s2[j++];
        }
    }

    s1[i] = '\0';
    
}

void expand(char s1[], char s2[]) {

    char start;
    char end;
    char s3[128];
    char c;
    int i;
    int j;

    for (i = 0; (c = s1[i++]) != '\0'; ) {
        // Look for leading and trailing - 
        if (c == '-' && (i - 1 == 0 || s1[i] == '\0')) {
            // Do nothing for now
            return;
        }
        else if (c == '-') {
            start = s1[i - 2];
            end = s1[i];
            singleExpand(start, end, s3);
            stringConcat(s2, s3);
        }
    }
}

int main(void) {

    char string[] = "a-z";
    char string1[128];

    expand(string, string1);
    printf("%s\n", string1);

    return 0;
}
