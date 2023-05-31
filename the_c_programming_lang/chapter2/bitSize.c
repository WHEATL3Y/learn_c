// The C Programming Language
// Excercise 2-1 
// Author: Jacob Christensen

#include <stdio.h>
#include <limits.h>
#include <float.h>

void intLimitsValues(void) {
    printf("Unsigned Char:\t0 - %u\n", UCHAR_MAX);
    printf("Signed Char:\t%d - %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Unsigned Short:\t0 - %u\n", USHRT_MAX);
    printf("Signed Short:\t%d - %d\n", SHRT_MIN, SHRT_MAX);
    printf("Unsigned Int:\t0 - %u\n", UINT_MAX);
    printf("Signed Int:\t%d - %d\n", INT_MIN, INT_MAX);
    printf("Unsigned Long:\t0 - %lu\n", ULONG_MAX);
    printf("Signed Long:\t%ld - %ld\n", LONG_MIN, LONG_MAX);
}

void floatLimitsValues(void) {

    printf("Float:\t\t%.10e - %.10e\n", FLT_MIN, FLT_MAX);
    printf("Double:\t\t%.10e - %.10e\n", DBL_MIN, DBL_MAX);
    printf("Long Double:\t%.10LE - %.10LE\n", LDBL_MIN, LDBL_MAX);
}
int main(void) {

    intLimitsValues();
    printf("\n");
    floatLimitsValues();

    return 0;
}
