#include <stdio.h>
#include <stdlib.h>

int gcd (int n, int d) {
    if (n > d)
        return gcd (n-d, d);
    if (n < d)
        return gcd (n, d-n);
    else
        return n;
}

int main (int argc, char* argv[]) {
    int productNumerator = 1;
    int productDenominator = 1;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= i; j++) {
            for (int k = 1; k <= 9; k++) {
                int numerator = j * 10 + i;
                int denominator = i * 10 + k;
                if (denominator >= numerator &&
                    denominator != numerator && 
                    denominator * j == numerator * k) {
                    productNumerator *= numerator;
                    productDenominator *= denominator;
                }
            }
        }
    }
    int greatestCommonDivisor = gcd (productNumerator, productDenominator);
    printf ("%d\n", productDenominator / greatestCommonDivisor);
}
