// The C Programming Language
// Excercise 2-1 
// Author: Jacob Christensen

#include <stdio.h>
#include <float.h>

int main(void) {

    printf("This is not accurate, for testing only!\n");
    float testFloat = 1;
    double testDouble = 1;
    long double testLongDouble = 1;

    // Flag for loop control
    int testing = 1;
    long long int temp;
    float highest;

    while (testing) {
        temp = (int) testFloat;
        
        if ((float)(temp <<= 1) <= 0) {
            printf("Calculated Value: %.10e\n", (float) (temp >>= 1));
            testing = 0;
        }
        testFloat = (float) temp;
        printf("%.10e\n", testFloat);
    }

    printf("Header Value: %.10e\n", FLT_MIN);

    return 0;
}
