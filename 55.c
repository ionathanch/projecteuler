#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

long long reverse (long long n) {
    long long num = n;
    long long reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}

bool isPalindrome(long long n) {
    return n == reverse (n);
}

bool isLychrel (int n) {
    long long num = n;
    int lychrel = true;
    int count = 0;
    while (lychrel && count < 50) {
        num += reverse (num);
        lychrel = !isPalindrome (num);
        count++;
    }
    return lychrel;
}

int main () {
    int lychrels = 0;
    for (int i = 1; i < 10000; i++) {
        bool lychrel = isLychrel (i);
        if (lychrel)
            lychrels++;
    }
    printf ("%d Lychrels\n", lychrels);
}
