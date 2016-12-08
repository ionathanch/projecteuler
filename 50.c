#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "primes.h"

int main () {
    int n = 1000000;
    long* primes;
    bool* primesTable;
    long numPrimes = listOfPrimes (n, &primes, &primesTable);

    int terms = 22;
    int mostTerms = terms;
    int largestSum = 953;
    while (terms < n) {
        int sum = 0;
        for (int i = 0; i < terms; i++) {
            sum += primes[i];
        }

        if (sum > n)
            break;
        if (primesTable[sum]) {
            mostTerms = terms;
            largestSum = sum; 
            terms++;
            continue;
        }
        
        for (int j = terms; j < n; j++) {
            sum += primes[j] - primes[j - terms];
            if (sum > n)
                break;
            if (primesTable[sum]) {
                mostTerms = terms;
                largestSum = sum;
                break;
            }
        }

        terms++;
    }
    printf ("%d terms: %d\n", mostTerms, largestSum);

    free (primes);
    free (primesTable);
}
