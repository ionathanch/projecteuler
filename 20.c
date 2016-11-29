#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Using Stirling's approximation, 
// n! ~ sqrt(2*pi*n) * (n/e)^n
// ln(n!) ~ 0.5*ln(2*pi*n) + n*ln(n) - n
// So the number of digits of n! is around
// log(n!) = ln(n!)/ln(10)
//         ~ (0.5*ln(2*pi*n) + n*ln(n) - n)/ln(10)

int getFactorialDigits(double n) {
    return ceil((0.5*log(2.0*M_PI*n) + n*log(n) - n)/log(10.0));
}

int main (int argc, char* argv[]) {
    int len = getFactorialDigits(100.0);
    char* num = calloc (len, sizeof (char));
    num[0] = 1;

    for (int i = 1; i <= 100; i++) {
        int carry = 0;
        for (int j = 0; j < len; j++) {
            int new_carry = (carry + num[j] * i) / 10;
            num[j] = (carry + num[j] * i) % 10;
            carry = new_carry;
        }
    }

    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += num[i];
        printf("%d", num[i]);
    }
    free (num);

    printf("\n%d\n", sum);
}
