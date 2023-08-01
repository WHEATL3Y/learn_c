// Effective C
// Chapter 3: Increment test 
// Author Jacob Christensen

#include <stdio.h>
#include <stdlib.h>

int main(void) {
   
    int i;
    int n = 0;    

    for (i = 0; i < 5; i++) {
        printf("%d\n", n++);
    }

    return EXIT_SUCCESS;
}
