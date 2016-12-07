#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool isPentagonal (long long n) {
    long long radicand = 24*n + 1;
    long long sqrtr = sqrt (radicand);
    return sqrtr * sqrtr == radicand && (sqrtr + 1) % 6 == 0;
}

int main () {
    long long n = 144LL;
    while (true) {
        long long hex = n * (2*n - 1);
        if (isPentagonal (hex)) {
            printf ("%lli\n", hex);
            break;
        }
        n++;
    }
}
