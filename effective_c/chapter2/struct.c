// Effective C
// Chapter 2: Structure 
// Author Jacob Christensen

#include <stdio.h>
#include <stdlib.h>

#define PRINT_BLANK printf("\n");

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

    // Typedef
    typedef struct Address {
        int number;
        char street[255];
        char city[255];
        char state[3];
        int zip;
    } Address;

    Address home = {6611, "Club Villa Rd", "Parker", "CO", 80134};

    PRINT_BLANK
    printf("%d %s\n%s, %s %d\n", home.number, home.street, home.city, home.state, home.zip);

    return EXIT_SUCCESS;
}
