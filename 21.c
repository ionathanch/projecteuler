/*
   Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
   If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

   For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

   Evaluate the sum of all the amicable numbers under 10000.
*/

#include <stdio.h>
#include <stdlib.h>

int sumOfDivisors[10001];

void findSumOfProperDivisors () {
    sumOfDivisors[0] = 0; // placeholder
    for (int i = 1; i <= 10000; i++) {
        int sumOfDivisorsOfI = 1;
        for (int j = 2; j * j <= i; j++) {
            if (j * j == i)
                sumOfDivisorsOfI += j;
            else if (i % j == 0)
                sumOfDivisorsOfI += j + i / j;
        }
        sumOfDivisors[i] = sumOfDivisorsOfI;
    }
}

int sumOfAmicable () {
    int sum = 0;
    for (int i = 1; i <= 10000; i++) {
        int value = sumOfDivisors[i];
        if (value <= 10000 && value != i && sumOfDivisors[value] == i) {
            sum += i;
            printf("%d, %d\n", i, value);
        }
    }
    return sum;
}

int main (int argc, char* argv[]) {
    findSumOfProperDivisors ();
    printf ("%d\n", sumOfAmicable ());
}
