#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int try = 3000;
int* pentagonalTable;
int* pentagonals;

bool isPentagonal (int n) {
    if (n < try && pentagonalTable[n] == -1)
        return false;
    if (n < try && pentagonalTable[n] == 1)
        return true;
    else {
        int radicand = 24*n + 1;
        int sqrtr = sqrt (radicand);
        if (sqrtr * sqrtr == radicand && (sqrtr + 1) % 6 == 0) {
            if (n < try)
                pentagonalTable[n] = 1;
            return true;
        }
        else {
            if (n < try)
                pentagonalTable[n] = -1;
            return false;
        }
    }
}

int pentagonalize (int n) {
    if (n < try) {
        if (pentagonals[n] == 0) {
            pentagonals[n] = n * (3*n - 1) / 2;
            if (pentagonals[n] < try)
                pentagonalTable[pentagonals[n]] = 1;
        }
        return pentagonals[n];
    }
    else
        return n * (3*n - 1) / 2;
}

int main () {
    pentagonalTable = calloc (try, sizeof (int));
    pentagonals = calloc (try, sizeof (int));
    for (int j = 1; j < try; j++) {
        for (int k = 1; k < j; k++) {
            int pj = pentagonalize (j);
            int pk = pentagonalize (k);
            if (isPentagonal (pj + pk) && isPentagonal (pj - pk)) {
                printf ("j: %d; k: %d; Pj: %d; Pk: %d; D: %d", j, k, pj, pk, pj - pk);
            }
        }
    }
}
