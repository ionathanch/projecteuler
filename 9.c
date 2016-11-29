#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]) {
    for (int i = 1; i < 334; i++) {
        for (int j = i; j < (1000 - i)/2 + 1; j++) {
            int k = 1000 - i - j;
            if (i*i + j*j == k*k ||
                i*i + k*k == j*j ||
                j*j + k*k == i*i)
                printf("%d, %d, %d, %d\n", i, j, k, i*j*k);
        }
    }

    return 0;
}
