// The C Programming Language
// Excercise: 4-14 
// Author: Jacob Christensen

#include <stdio.h>

#define swap(t, x, y) { \
    t temp = x; \
    x = y; \
    y = temp; \
}

int main(void) {

    int test1 = 1;
    int test2 = 2;
    printf("test1 = %d, test2 = %d\n", test1, test2);
    swap(int, test1, test2);
    printf("test1 = %d, test2 = %d\n", test1, test2);
    
    return 0;

}
