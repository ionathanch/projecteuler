#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int champernowneDigit (int n) {
    int d = 1;
    int next = 9;
    while (n > next) {
        n -= next;
        next = 9 * ++d * (int) pow (10, d - 1);
    }

    for (int k = 1; k <= d; k++) {
        if ((n - k) % d == 0) {
            return (((n - k) / (d * (int) pow (10, d - k))) % 10) + (k == 1 ? 1 : 0);
        }
    }
}

int main () {
    int product = 1;
    for (int i = 1; i <= 1000000; i *= 10) {
        product *= champernowneDigit (i);
    }
    printf ("%d\n", product);
}
