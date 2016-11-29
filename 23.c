/*
   A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

   A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

   As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

   Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool abundance[28124];

void findAbundances() { 
    for (int i = 0; i < 12; i++) {
        abundance[i] = false;
    }

    for (int i = 12; i < 28124; i++) {
        int sumOfProperDivisors = 0;
        for (int j = 1; j < i / 2 + 1; j++) {
            if (i % j == 0)
                sumOfProperDivisors += j;
        }
        abundance[i] = sumOfProperDivisors > i;
    }
}

bool isSumOfAbundances(int n) {
    for (int i = 12; i < n / 2 + 1; i++) {
        if (abundance[i] && abundance[n - i])
            return true;
    }
    return false;
}

int main (int argc, char* argv[]) {
    findAbundances();

    int sumOfNotSumOfAbundances = 0;
    for (int i = 1; i < 28124; i++) {
        if (!isSumOfAbundances(i))
            sumOfNotSumOfAbundances += i;
    }

    printf("%d\n", sumOfNotSumOfAbundances);
}
