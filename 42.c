#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

bool isPerfectSquare (int n) {
    int sqrtn = (int) sqrt (n);
    return sqrtn * sqrtn == n;
}

bool isTriangular (int n) {
    return isPerfectSquare (8*n+1);
}

int main () {
    FILE* fp = fopen ("p042_words.txt", "r");
    char file[16 * 1024]; // 16 KiB
    fgets (file, 16 * 1024, fp);

    int numOfTriangular = 0;
    char* token = strtok (file, ",");
    while (token != NULL) {
        int value = 0;
        for (int c = 0; c < strlen (token); c++) {
            if (token[c] >= 'A' && token[c] <= 'Z')
                value += token[c] - 'A' + 1;
        }

        if (isTriangular (value)) {
            numOfTriangular++;
            printf ("%s: %d\n", token, value);
        }

        token = strtok (NULL, ",");
    }

    printf ("%d\n", numOfTriangular);
}
