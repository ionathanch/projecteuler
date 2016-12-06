#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool hasUniqueDigits (int i) {
    int a = i % 10;
    i /= 10;
    int b = i % 10;
    i /= 10;
    int c = i % 10;
    i /= 10;
    int d = i % 10;
    return  a != b && a != c && a != d &&
            b != c && b != d &&
            c != d;
}

bool isPandigital (int i, int j) {
    int a = i % 10;
    i /= 10;
    int b = i % 10;
    i /= 10;
    int c = i % 10;
    i /= 10;
    int d = i % 10;
    
    int e = j % 10;
    j /= 10;
    int f = j % 10;
    j /= 10;
    int g = j % 10;
    j /= 10;
    int h = j % 10;
    j /= 10;
    int k = j % 10;

    return  a != 0 && b != 0 && c != 0 && d != 0 && e != 0 && f != 0 && g != 0 && h != 0 && k != 0 &&
            a != b && a != c && a != d && a != e && a != f && a != g && a != h && a != k &&
            b != c && b != d && b != e && b != f && b != g && b != h && b != k &&
            c != d && c != e && c != f && c != g && c != h && c != k &&
            d != e && d != f && d != g && d != h && d != k &&
            e != f && e != g && e != h && e != k &&
            f != g && f != h && f != k &&
            g != h && g != k && 
            h != k;
}

int main () {
    int n = 9182;
    for (int i = 9183; i <= 9876; i++) {
        if (hasUniqueDigits (i)) {
            if (isPandigital (i, 2 * i))
                n = i;
        }
    }
    printf ("%d%d\n", n, 2 * n);
}
