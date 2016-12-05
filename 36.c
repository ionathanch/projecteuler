#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

void intToDecimalString (int n, char** string) {
    *string = malloc (sizeof (char) * (int)(floor (log10 (n)) + 1));
    sprintf (*string, "%d", n);
}

void intToBinaryString (int n, char** string) {
    char hex[9];
    sprintf (hex, "%x", n);

    char bins[16][5] = { "0000", "0001", "0010", "0011",
                         "0100", "0101", "0110", "0111",
                         "1000", "1001", "1010", "1011",
                         "1100", "1101", "1110", "1111" };

    *string = malloc (sizeof (char) * 33);
    (*string)[0] = '\0';
    for (int c = 0; c < 9; c++) {
        if (hex[c] >= '0' && hex[c] <= '9') {
            strcat (*string, bins[hex[c] - '0']);
        }
        else if (hex[c] >= 'a' && hex[c] <= 'z') {
            strcat (*string, bins[hex[c] - 'a' + 0xa]);
        }
    }
}

bool isPalindrome (char* string) {
    int index = 0;
    while (string[index] == '0')
        index++;

    bool palindromic = true;
    int len = strlen (string);
    for (int i = 0; i < (len - index) / 2; i++) {
        if (string[index + i] != string[len - i - 1]) {
            palindromic = false;
            break;
        }
    } 

    return palindromic;
}

int main () {
    int sum = 0;
    for (int i = 1; i < 1000000; i++) {
        char* decimal;
        intToDecimalString (i, &decimal);
        char* binary;
        intToBinaryString (i, &binary);
        if (isPalindrome (decimal) && isPalindrome (binary)) {
            sum += i;
            printf ("%s, %s\n", decimal, binary);
        }
        free (decimal);
        free (binary);
    }
    printf ("%d\n", sum);
}
