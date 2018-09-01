// largest prime i where i^2 + 2^3 + 2^4 = 50000000 is 7069
// largest prime j where 2^2 + j^3 + 2^4 = 50000000 is 367
// largest prime k where 2^2 + 2^3 + k^4 = 50000000 is 83

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "primes.h"

#define SIZE 50000000

int main(void) {
    long* primes;
    bool* primesTable;
    int length = listOfPrimes(sqrt(SIZE - 24), &primes, &primesTable);
    bool* visited = calloc(SIZE, sizeof(bool));
    int count = 0;

    for (int i = 0; i < length && primes[i] <= 7069; i++) {
        for (int j = 0; j < length && primes[j] <= 367; j++) {
            for (int k = 0; k < length && primes[k] <= 83; k++) {
                int n = pow(primes[i], 2) + pow(primes[j], 3) + pow(primes[k], 4);
                if (n < SIZE && !visited[n]) {
                    count++;
                    visited[n] = true;
                }
            }
        }
    }

    printf("%d\n", count);

    free(primes);
    free(primesTable);
    free(visited);
}