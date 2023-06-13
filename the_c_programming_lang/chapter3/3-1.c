// The C Programming Language
// Excercise: 3-1
// Author: Jacob Christensen

#include <stdio.h>

int binsearch1(int x, int v[], int n) {

    int low = 0;
    int high = n;
    int mid;

    while (low < high) {
        mid = (low + high) / 2;
        if (x < v[mid]) {
            high = mid;
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

int binsearch2(int x, int v[], int length) {

    int high = length;
    int low = 0;
    int mid = high / 2;

   
    while (low < high && mid != x) {
        mid = (high + low) / 2;
        if (x < v[mid]) {
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }

    if (v[mid] == x) {
        return mid;
    }
    else {
        return -1;
    }
}

int main(void) {

    int data[] = {0, 1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12, 13};
    printf("%d\n", binsearch1(0, data, 13));
    printf("%d\n", binsearch2(0, data, 13));
    return 0;
}
