#include <stdio.h>

main () {
    printf("EOF = %d\n", EOF);
    // return_input();
    count_text();
}

void return_input() {
    int c;

    while ((c = getchar()) != EOF) {
        putchar(c);
    }
}

void count_text() {
    long nc;
    long nl;
    long ns;
    long nt;
    int c;

    nc = 0;
    nl = 0;
    ns = 0;
    nt = 0;

    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n') {
            ++nl;
        }
        if (c == '\t') {
            ++nt;
        }
        if (c == ' ') {
            ++ns;
        }

    }
    printf("Characters\t%ld\n", nc);
    printf("Lines\t\t%ld\n", nl);
    printf("Words\t\t%ld\n", ns);
    printf("Tabs\t\t%ld\n", nt);
}