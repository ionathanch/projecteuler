#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char* n = argv[1];

    if (strlen(n) < 13) 
        printf("%s\n", "Your number has less than 13 digits, which may cause undefined behaviour.");

    long long largestProduct = 1;
    for (int k = 0; k < strlen(n) - 12; k++) {
        long long product = 1;
        for (int j = 0; j < 13; j++) {
            product *= (n[j+k]-'0');
        }
        if (product > largestProduct) {
            largestProduct = product;
        }
    }

    printf("%lli\n", largestProduct);
    return 0;
}
