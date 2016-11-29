#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool isPrime(long n) {
    for (long i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main(int argc, char* argv[]) {
    int j = 0;
    int jthPrime = 0;
    for (long i = 2; j < 10001; i++) {
        if (isPrime(i)) {
            j++;
            jthPrime = i;
            // printf("%d: %d\n", j, jthPrime);
        }
    }
    printf("%d\n", jthPrime);
    return 0;
}
