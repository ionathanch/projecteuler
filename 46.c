#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "primes.h"

int main () {
    long size = 10000;
    long* primes;
    bool* primesTable;
    long numPrimes = listOfPrimes (size, &primes, &primesTable);
    long n = 37;
    while (n < size) {
        if (!primesTable[n]) {
            long p = 0;
            bool decomposable = false;
            while (n > primes[p]) {
                long sq = (n - primes[p]) / 2;
                long sqrtr = sqrt (sq);
                if (sqrtr * sqrtr == sq) {
                    // printf ("%lli = %lli + 2 x %lli²\n", n, primes[p], sqrtr);
                    decomposable = true;
                    n += 2;
                    break;
                }
                else
                    p++;
            }
            if (!decomposable) {
                printf ("%lli cannot be written as such.\n", n);
                break;
            }
        }
        else
            n += 2;
    }
}
