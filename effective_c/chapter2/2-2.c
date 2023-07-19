// Effective C
// Chapter 2: 2-2 
// Author Jacob Christensen

#include <stdio.h>
#include <stdlib.h>

void func0(void);
void func1(void);
void func2(void);
void caller(int);

void (*ptrArray[3]) (void) = {func0, func1, func2};

void func0(void) {
    printf("This is Function 0\n");
}

void func1(void) {
    printf("This is Function 1\n");
}

void func2(void) {
    printf("This is Function 2\n");
}

void caller(int n) {
    
    ptrArray[n]();
    
}

int main(void) {
    
    caller(0);
    caller(1);
    caller(2);

    return EXIT_SUCCESS;

}
