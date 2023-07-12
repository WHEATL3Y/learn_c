// The C Programming Language
// Excercise: String Pointers 
// Author: Jacob Christensen

#include <stdio.h>

int main(void) {

    char *string = "Hello World\n";
    printf("%s\n", string);
    printf("%c\n", *string++);
    printf("%i\n", *string);
    return 0;
}
