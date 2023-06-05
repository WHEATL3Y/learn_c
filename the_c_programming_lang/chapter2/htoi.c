// The C Programming Language
// Excercise 2-3 
// Author: Jacob Christensen

#include <stdio.h>
#include <string.h>
#include <math.h>

int htoi(char s[]) {
    
    int i = 0;
    int c;
    int value = 0;
    int charVal;
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
