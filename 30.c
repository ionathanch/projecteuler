#include <stdio.h>
#include <stdlib.h>

int powersOfFive[10] = { 0, 1, 32, 243, 1024, 3125, 7776, 16807, 32768, 59049 };

int main (int argc, char* argv[]) {
    int sumOfNum = 0;
    for (int i = 200; i <= 354294; i++) {
        int n = i;
        int sumOfDig = 0;
        while (n > 0) {
            sumOfDig += powersOfFive[n % 10];
            n /= 10;
        }
        if (sumOfDig == i) {
            sumOfNum += i;
            printf ("%d\n", i);
        }
    }

    printf ("sum: %d\n", sumOfNum);
}
