#include <stdio.h>
#include <stdlib.h>

long long choose (int n, int r) {
    long long numerator = 1;
    long long denominator = 1;
    for (int i = 1; i <= r; i++) {
        numerator *= n + 1 - i;
        denominator *= i;
    }
    printf ("%d choose %d = %lli\n", n, r, numerator/denominator);
    return numerator / denominator;
}

int main () {
    int count = 4;
    int n = 24;
    int r = 10;

    while (n <= 100) {
        while (choose (n, r-1) > 1000000)
            r--;
        count += n - 2*r + 1;
        n++;
    }
    printf ("Final r: %d; count: %d\n", r, count);
}
