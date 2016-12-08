#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "primes.h"

int numOfPrimeFactors (int n, long* primes) {
    int rem = n;
    int factors = 0;
    for (int i = 0; primes[i] <= rem && primes[i] != n; i++) {
        if (rem % primes[i] == 0) {
            factors++;
            while (rem != 0 && rem % primes[i] == 0) {
                rem /= primes[i];
            }
            if (rem == 0)
                break;
        }
    }
    return factors;
}

int main () {
    long n = 200000;
    long* primes;
    bool* primesTable;
    listOfPrimes (n, &primes, &primesTable);

    int consec = 0;
    for (long i = 5; i <= n; i++) {
        int factors = numOfPrimeFactors (i, primes);
        consec = (factors == 4 ? consec + 1 : 0);
        if (consec == 4) {
            printf ("%d\n", i - 3);
            break;
        }
    }
}
