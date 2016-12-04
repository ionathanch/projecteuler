#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPandigital (int a, int b, int c, int d, int e, int product) {
    if (product < 9999) {
        int thous = product;
        int ones = thous % 10;
        thous /= 10;
        int tens = thous % 10;
        thous /= 10;
        int hunds = thous %  10;
        thous /= 10;

        return  ones != 0 && tens != 0 && hunds != 0 && thous != 0 &&
                ones != a && ones != b && ones != c && ones != d && ones != e &&
                tens != a && tens != b && tens != c && tens != d && tens != e &&
                hunds != a && hunds != b && hunds != c && hunds != d && hunds != e &&
                thous != a && thous != b && thous != c && thous != d && thous != e &&
                ones != tens && ones != hunds && ones != thous &&
                tens != hunds && tens != thous &&
                hunds != thous;
    }
    return false;
}

void oneByFour (int a, int b, int c, int d, int e) {
    // a x bcde = _ _ _ _
    if (a > 1 && a < 9) {
        int multiplier = b * 1000 + c * 100 + d * 10 + e;
        int product = a * multiplier;

        if (isPandigital (a, b, c, d, e, product))
            printf ("%d x %d = %d\n", a, multiplier, product);
    }
}

void twoByThree (int a, int b, int c, int d, int e) {
    // ab x cde = _ _ _ _
    int multiplicand = a * 10 + b;
    int multiplier = c * 100 + d * 10 + e;
    int product = multiplicand * multiplier;

    if (isPandigital (a, b, c, d, e, product))
        printf ("%d x %d = %d\n", multiplicand, multiplier, product);
}

int main (int argc, char* argv[]) {
    for (int a = 1; a <= 9; a++) {
        for (int b = 1; b <= 9; b++) {
            if (a == b)
                continue;
            for (int c = 1; c <= 9; c++) {
                if (c == b || c == a)
                    continue;
                for (int d = 1; d <= 9; d++) {
                    if (d == c || d == b || d == a)
                        continue;
                    for (int e = 1; e <= 9; e++) {
                        if (e == d || e == c || e == b || e == a)
                            continue;

                        oneByFour  (a, b, c, d, e);
                        twoByThree (a, b, c, d, e);
                    }
                }
            }
        }
    }
}
