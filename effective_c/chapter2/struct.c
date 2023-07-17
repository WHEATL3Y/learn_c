// Effective C
// Chapter 2: Structure 
// Author Jacob Christensen

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int i;
    struct Person {
        char name[255];
        int age;
    };

    struct Person people[2];
    struct Person jacob = {"Jacob", 26};
    struct Person claire = {"Claire", 26};

    people[0] = jacob;
    people[1] = claire;

    for (i = 0; i < 2; i++) {
        printf("%s is %d years old\n", people[i].name, people[i].age);
    }

    return EXIT_SUCCESS;
}
