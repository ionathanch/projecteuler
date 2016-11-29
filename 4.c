#include <stdlib.h>
#include <stdio.h>

int checkIfPalindromic(int n) {
    int num = n;
    int rev = 0;
    while (num > 0) {
        int deg = num % 10;
        rev = rev * 10 + deg;
        num = num / 10;
    }
    return n == rev;
}

int main (int argc, char* argv[]) {
    int maxPalindrome = 0;
    for (int i = 999; i >= 100; i--) {
        for (int j = 999; j >= i; j--) {
            int prod = i*j;
            if (checkIfPalindromic(prod) && 
                    prod > maxPalindrome) { 
                maxPalindrome = prod;
            }
        }
    }
    printf("%d\n", maxPalindrome);
    return 0;
}
