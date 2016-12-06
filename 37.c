#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "primes.h"

bool* primesTable;

bool isLeftTrunc (int n) {
    int digits = floor (log10 (n)) + 1;
    for (int i = 1; i <= digits; i++) {
        if (!primesTable[n % (int) pow (10, i)])
            return false;
    }
    return true;
}

bool isRightTrunc (int n) {
    while (n > 0) {
        if (!primesTable[n])
            return false;
        n /= 10;
    }
    return true;
}

int main () {
    int* primes;
    int numOfPrimes = listOfPrimes (1000000, &primes, &primesTable);
    // unfortunately I couldn't find a deterministic way to find
    // the upper-bound of all truncatable primes... 1 mil will do
    
    int sum = 0;
    for (int i = 0; i < numOfPrimes; i++) {
        if (isLeftTrunc (primes[i]) &&
            isRightTrunc (primes[i]) &&
            primes[i] > 10) {
            printf ("%d\n", primes[i]);
            sum += primes[i];
        }
    }
    printf ("sum: %d\n", sum);
}
