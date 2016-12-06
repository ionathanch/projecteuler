#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "primes.h"

bool isPandigital (int n) {
    if (n < 1 || n > 987654321)
        return false;
    
    int digits = floor (log10 (n)) + 1;
    bool* seen = calloc (digits, sizeof (bool));
    while (n > 0) {
        int digit = n % 10;
        if (digit == 0 || seen[digit - 1])
            return false;
        seen[digit - 1] = true;
        n /= 10;
    }
    for (int d = 0; d < digits; d++) {
        if (!seen[d])
            return false;
    }
    return true;
}

int main () {
    long* primes;
    bool* primesTable;
    long numPrimes = listOfPrimes (7654321, &primes, &primesTable);
    for (long i = numPrimes; i > 0; i--) {
        if (isPandigital (primes[i])) {
            printf ("%d\n", primes[i]);
            break;
        }
    }
}
