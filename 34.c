#include <stdio.h>
#include <stdlib.h>

int factorial[10] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };

int main (int argc, char* argv[]) {
    int max = 2540160;  // 7 * 9!
    int sumOfNum = 0;
    for (int i = 10; i <= max; i++) {
        int sumOfDigFact = 0;
        int remainder = i;
        while (remainder > 0) {
            sumOfDigFact += factorial [remainder % 10];
            remainder /= 10;
        }
        if (sumOfDigFact == i)
            sumOfNum += i;
    }
    printf ("%d\n", sumOfNum);
}
