#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPrimeDivisible (int* digits) {
    // d2d3d4 divisible by 2
    bool value =    digits[3] == 0 || 
                    digits[3] == 2 || 
                    digits[3] == 4 || 
                    digits[3] == 6 || 
                    digits[3] == 8;

    // d3d4d5 divisible by 3
    value = value && (digits[2] + digits[3] + digits[4]) % 3 == 0;

    // d4d5d6 divisible by 5
    value = value && (digits[5] == 0 || digits[5] == 5);

    // d5d6d7 divisible by 7
    value = value && (digits[6] + digits[5]*3 + digits[4]*2) % 7 == 0;

    // d6d7d8 divisible 11
    int divSum = digits[5] - digits[6] + digits[7];
    value = value && (divSum == 0 || divSum == 11); 

    // d7d8d9 divisible by 13
    divSum = digits[6]*10 + digits[7] - digits[8]*9;
    value = value && divSum % 13 == 0;

    // d8d9d10 divisible by 17
    divSum = digits[7]*10 + digits[8] - digits[9]*5;
    value = value && divSum % 17 == 0;

    return value;
}

long long intArrayToInt (int* array) {
    return  array[0] * 1000000000LL +
            array[1] * 100000000LL  +
            array[2] * 10000000LL   +
            array[3] * 1000000LL    +
            array[4] * 100000LL     +
            array[5] * 10000LL      +
            array[6] * 1000LL       +
            array[7] * 100LL        +
            array[8] * 10LL         +
            array[9] * 1LL;
}

int main () {
    long long sum = 0;
    int num[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int k = 8;
    while (k >= 0) {
        if (num[k] < num[k+1]) {
            for (int l = 9; l > k; l--) {
                if (num[k] < num[l]) {
                    int temp = num[l];
                    num[l] = num[k];
                    num[k] = temp;

                    int* rev = malloc (sizeof (int) * (9 - k));
                    for (int r = k + 1; r < 10; r++) {
                        rev[r - k - 1] = num[r];
                    }
                    for (int r = k + 1; r < 10; r++) {
                        num[r] = rev[9-r];
                    }
                    free (rev);
                    
                    if (isPrimeDivisible (num))
                        sum += intArrayToInt (num);

                    k = 8;
                    break;
                }
            }
        }
        else {
            k--;
        }
    }
    printf ("%lli\n", sum);
}
