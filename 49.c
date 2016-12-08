#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "primes.h"

bool arePermutations (int a, int b, int c) {
    int aDigOcc[10] = {0};
    int bDigOcc[10] = {0};
    int cDigOcc[10] = {0};

    for (int i = 0; i < 4; i++) {
        aDigOcc[a % 10]++;
        a /= 10;

        bDigOcc[b % 10]++;
        b /= 10;

        cDigOcc[c % 10]++;
        c /= 10;
    }

    for (int i = 0; i < 10; i++) {
        if (aDigOcc[i] != bDigOcc[i] || bDigOcc[i] != cDigOcc[i] || cDigOcc[i] != aDigOcc[i])
            return false;
    } 
    return true;
}

int main () {
    long* primes;
    bool* primesTable;
    listOfPrimes (10000, &primes, &primesTable);

    int sum = 0;
    for (int r = 1; r < 4499; r++) {
        for (int n = 1000; n < 9999 - 2 * r; n++) {
            int a = n;
            int b = n + r;
            int c = b + r;
            if (primesTable[a] && primesTable[b] && primesTable[c] && arePermutations (a, b, c))
                printf ("%d%d%d\n", a, b, c); 
        }
    }
}
