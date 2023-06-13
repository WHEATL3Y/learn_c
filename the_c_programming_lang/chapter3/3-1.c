// The C Programming Language
// Excercise: 3-1
// Author: Jacob Christensen

#include <stdio.h>

int binsearch(int x, int v[], int n) {

    int low = 0;
    int high = n - 1;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid]) {
            high = mid + 1;
        }
        else if (x > v[mid]) {
            low = mid + 1;
        }
        else {
            return mid;
        }
    }

    return -1;

}

/* int binsearch(int x, int v[], int length) { */
/*  */
/*     int high = length - 1; */
/*     int low = 0; */
/*     int mid = high / 2; */
/*  */
/*     */
/*     while (low < high && mid != x) { */
/*         mid = (high + low) / 2; */
/*         if (x < v[mid]) { */
/*             high = mid + 1; */
/*         } */
/*         else { */
/*             low = mid + 1; */
/*         } */
/*     } */
/*  */
/*     if (mid == x) { */
/*         return mid; */
/*     } */
/*     else { */
/*         return -1; */
/*     } */
/* } */

int main(void) {

    int data[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    printf("%lu\n", sizeof(data)/sizeof(*data));
    printf("%d\n", binsearch(4, data, 14));
    return 0;
}
