#include <stdio.h>

unsigned long long fib(unsigned long long n) {
    if (n < 2) {
        return n;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}

int main() {
    printf("%llu\n", fib(20));
    return 0;
}