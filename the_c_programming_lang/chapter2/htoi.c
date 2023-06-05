// The C Programming Language
// Excercise 2-3 
// htoi.c: Convert hex string to int decimal value
// Author: Jacob Christensen

#include <stdio.h>
#include <string.h>
#include <math.h>

int htoi(char s[]) {
   
    // Hex to decimal conversion example
    // 7CF = (7 * 16^2) + (12 * 16^1) + (15 * 16^0)

    int c;
    int charVal;
    int i = 0;
    int value = 0;
    int length = strlen(s) - 1;

    if (s[0] == '0' && s[1] == 'x' || s[1] == 'X') {
        i = 2;
        length -= 2;
    } 
    
    for (; (c = s[i]) != '\0'; i++, length--) {
        if (c >= '0' && c <= '9') {
            charVal = (c - '0') * (int) pow(16, length);
            value += charVal;
        } else if (c >= 'A' && c <= 'Z') {
            charVal = (c - 'A' + 10) * (int) pow(16, length);
            value += charVal;
        } else if (c >= 'a' && c <= 'z') {
            charVal = (c - 'a' + 10) * (int) pow(16, length);
            value += charVal;
        } else {
            return -1;
        }
    }
    
    return value;

}

int main(void) {

    printf("%d\n", htoi("0x0FF1CE"));
    return 0;
}
