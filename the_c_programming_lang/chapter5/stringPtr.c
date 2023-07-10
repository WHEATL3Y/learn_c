// The C Programming Language
// Excercise: String Pointers 
// Author: Jacob Christensen

#include <stdio.h>

int main(void) {

    char *string = "Hello World\n";
    printf("%s", string);
    printf("%c", *string++);
    return 0;
}
