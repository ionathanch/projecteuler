#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool isPrime (int n) {
    int i = 2;
    while (i*i <= n) {
        if (n % i == 0)
            return false;
        i++;
    }
    return true;
}

int main () {
    int side = 7;
    int diagonals = 13;
    int primes = 8;
    while ((double) primes / diagonals > 0.1) {
        side += 2;
        diagonals += 4;
        for (int n = 0; n < 4; n++) {
            if (isPrime(side*side - n*(side - 1)))
                primes++;
        }
    }
    printf ("side length: %d\n", side);
}
