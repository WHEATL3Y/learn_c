// The C Programming Language
// Excercise: 3-5
// Author: Jacob Christensen

#include <stdio.h>

int strLength(char s[]) {
    // Return the length of s, not including '\0'
    int i;

    for (i = 0; s[i] != '\0'; i++) {
        ;
    }

    return i;

}

void reverse(char s[]) {
    // Reverse s in place;
    
    int i;
    int j;
    char t;

    for (i = 0, j = strLength(s) - 1; j >= i; i++, j--) {
        t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
}

void itob(int n, char s[], int b) {
    // Convert n to base b, store the result in s
    // Base2 (Binary) to Base36 (Hexatrigesimal)

    int r;
    int i;

    do {
        r = n % b;
        if (r > 9) {
            r += 55;
        }
        else if (r < 9) {
            r += 48;
        }
        s[i++] = r;
    } while ((n /= b) != 0);

    s[i] = '\0';
    reverse(s);
}

int main(void) {

    int number = 390293;
    int base = 25;
    char result[1000];
    
    itob(number, result, base);
    printf("%i (Base10) = %s (Base%i)\n", number, result, base);
    
    return 0;
}
