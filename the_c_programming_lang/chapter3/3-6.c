// The C Programming Language
// Excercise: 3-6 
// Author: Jacob Christensen

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

int length(char s[]) {

    int i;

    for (i = 0; s[i++] != '\0'; ) {
        ;
    }

    return i - 1;

}

void reverse(char s[]) {

    int i;
    int j = length(s) - 1; 
    char temp;

    for (i = 0; i < j; i++, j--) {
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
    }
}

void leftPad(char s[], int n) {
    // Pad 0s to the front of s, until len s = n

    int l = length(s);
    char s1[l + (n - l) + 1];
    int i = 0;
    int j = 0;
   
    if (l > n) {
        return; 
    }

    strcpy(s1, s);
    
    if (s[0] == '-') {
        l -= 2;
        i++;
        j++;
    }

    for (; i < n - l;) {
        s[i++] = '0';
    }

    for (; s1[j] != '\0';) {
        s[i++] = s1[j++];
    }

    s[i++] = '\0'; 
}

void itoa(int n, char s[]) {

    int i = 0;
    int sign = n;
    unsigned n1;

    if (n < 0) {
        n1 = (~n) + 1; 
    } 
    else {
        n1 = n;
    }

    do {
        s[i++] = n1 % 10 + '0';
    } while ((n1 /= 10) > 0);

    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
    leftPad(s, 15);
}

int main(void) {

    int n = 214320937;
    char string[MAX_LENGTH];
    itoa(n, string);

    printf("%s\n", string);
    return 0;
}
