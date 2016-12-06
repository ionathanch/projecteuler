#include <stdlib.h>
#include <stdio.h>

int main () {
    int maxP = 12;
    int maxSols = 1;
    for (int p = 12; p <= 1000; p++) {
        int sols = 0;
        for (int c = 1; c <= p - 2; c++) {
            for (int a = 1; a <= (p - c - 1) / 2; a++) {
                int b = p - c - a;
                if (a * a + b * b == c * c)
                    sols++;
            }
        }
        if (sols > maxSols) {
            maxSols = sols;
            maxP = p;
        }
    }
    printf ("%d\n", maxP);
}
