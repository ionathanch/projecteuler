#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "primes.h"

int main () {
    int bound = 1000000;

    long* primes;
    bool* primesTable;
    long numPrimes = listOfPrimes (bound, &primes, &primesTable);

    bool* circularPrimesTable = calloc (bound + 1, sizeof (bool));
    for (long i = 0; i < numPrimes; i++) {
        if (circularPrimesTable[primes[i]] != true) {
            long n = primes[i];
            int numOfDigits = floor (log10 (n)) + 1;
            int* digits = malloc (sizeof (int) * numOfDigits);
            for (int d = 0; d < numOfDigits; d++) {
                digits[d] = n % 10;
                n /= 10;
            }

            int* circles = malloc (sizeof (int) * numOfDigits);
            for (int c = 0; c < numOfDigits; c++) {
                circles[c] = 0;
                for (int d = c; d < c + numOfDigits; d++) {
                    circles[c] += digits[d % numOfDigits] * (int) pow (10, d - c);
                }
            }
            free (digits);

            bool circular = true;
            for (int c = 0; c < numOfDigits; c++) {
                if (primesTable[circles[c]] == false) {
                    circular = false;
                    break;
                }
            }
            if (circular) {
                for (int c = 0; c < numOfDigits; c++) {
                    circularPrimesTable[circles[c]] = true;
                }
            }
            free (circles);
        } 
    }

    free (primes);
    free (primesTable);

    int sum = 0;
    for (int i = 0; i <= bound; i++) {
        if (circularPrimesTable[i]) {
            sum++;
            printf ("%d ", i);
        }
    }
    free (circularPrimesTable);

    printf ("\n%d\n", sum);
}
