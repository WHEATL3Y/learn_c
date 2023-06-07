// The C Programming Language
// Excercise 2-4 
// Author: Jacob Christensen

#include <stdio.h>
#include <string.h>

int rmChar(char s1[], char s2[]) {
    // Removes each character in s1 that matches any character in s2.
    // Returns the number of characters removed.

    int removed = 0;
    int i1;
    int i2;
    int c1;
    int c2;
    int found;

    int i = 0;
    char newStr[strlen(s1) + 1];  

    for (i1 = 0; (c1 = s1[i1++]) != '\0'; ) {
        found = 1;
        for (i2 = 0; (c2 = s2[i2++]) != '\0'; ) {
            if (c1 == c2) {
                removed++;
                found = 0;
                break;
            }
        }
        if (found) {
            newStr[i++] = c1;
        }
    }
    
    newStr[i] = '\0';
    printf("%s\n", newStr);

    return removed;
}

int main(void) {

    char string1[] = "The drug seekers would come into the emergency room and scream about how much pain they were in. When you told them that you would start elevating their pain with Tylenol or Advil instead of a narcotic they became nasty and combative. They would start telling you what drug and dose they had to have to make their pain tolerable. After dealing with the same drug seekers several times a month it gets old. Some of the doctors would give in and give them a dose of morphine and send them away. Sure that was faster, but ethically she still couldn’t do it. Perhaps that’s why she had longer care times than the other doctors.";

    char string2[] = "disoenc";

    rmChar(string1, string2);
    return 0;
}
