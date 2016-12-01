#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPrime (int n) {
    switch (n) {
        case 1:
        case 9:
            return false;
        case 2:
        case 3:
        case 5:
        case 7:
            return true;
        default:
            break;
    }

    switch (n % 10) {
        case 0:
        case 2:
        case 4:
        case 5:
        case 6:
        case 8:
            return false;
        default:
            if ((n + 1) % 2 != 0)
                return false;
            for (int i = 3; i * i <= n; i += 2) {
                if (n % i == 0)
                    return false;
            }
            return true;
    }
}

bool* primeTable;

void findPrimes (int n) {
    primeTable = malloc (sizeof (bool) * (n + 1));
    for (int i = 0; i <= n; i++)
        primeTable[i] = isPrime (i);
}

int numOfPrimes (int a, int b) {
    for (int n = 0; n < b; n++) {
        int val = n * n + a * n + b;
        if (val < 0)
            val = -val;
        if (primeTable[val] == false)
            return n;
    }
}

int main (int argc, char* argv[]) {
    int maxVal = 999 * 999 + 999 * 999 + 1000;
    findPrimes (maxVal);

    int bestA = 0;
    int bestB = 0;
    int bestNum = 0;
    for (int a = 0; a < 1000; a++) {
        for (int b = 0; b <= 1000; b++) {
            if (primeTable[b] == true) {
                int n = numOfPrimes (a, b);
                if (n > bestNum) {
                    bestNum = n - 1;
                    bestA = a;
                    bestB = b;
                }

                n = numOfPrimes (a, -b);
                if (n > bestNum) {
                    bestNum = n;
                    bestA = a;
                    bestB = -b;
                }

                n = numOfPrimes (-a, b);
                if (n > bestNum) {
                    bestNum = n;
                    bestA = -a;
                    bestB = b;
                }

                n = numOfPrimes (-a, -b);
                if (n > bestNum) {
                    bestNum = n;
                    bestA = -a;
                    bestB = -b;
                }
            }
        }
    }

    printf ("a: %d, b: %d, n: %d, a*b: %d", bestA, bestB, bestNum, bestA * bestB);
}
