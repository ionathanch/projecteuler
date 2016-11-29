#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool isPrime (long n) {
    for (long i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main (int argc, char* argv[]) {
    long sumOfPrimes = 0;
    for (long i = 2; i < 2000000; i++) {
        if (isPrime(i))
            sumOfPrimes += i;
    }
}
