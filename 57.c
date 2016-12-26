#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
    long double numerator = 3;
    long double denominator = 2;
    int count = 0;
    for (int i = 0; i < 1000; i++) {
        long double newDen = numerator + denominator;
        long double newNum = newDen + denominator;
        numerator = newNum;
        denominator = newDen;
        if ((int) floor (log10 (numerator)) > (int) floor (log10 (denominator)))
            count++;
    }
    printf ("count: %d\n", count);
}
