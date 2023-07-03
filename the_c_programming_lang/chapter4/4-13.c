// The C Programming Language
// Excercise: 4-13 
// Author: Jacob Christensen

#include <stdio.h>

void reverse (char []);

void reverse(char s[]) {

    static int i;
    static int j;
    char t;

    if (++i < ++j) {
        reverse(s);
    }

    t = s[i];
    s[i] = s[j];
    s[j] = t;
    
}

int main(void) {

     

    return 0;
}
