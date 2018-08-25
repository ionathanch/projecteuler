// For a rectangle of dimensions n x m, there are a total of
// sum_{i=1}^n sum{j=1}^m i*j = 1/4 n(n+1)m(m+1) rectangles
// Therefore, we want to find nm such that n(n+1)m(m+1) is closest to 8 000 000
// We only need to try for values of n(n+1) up to ceil(sqrt(8000000)) = 2829
// which means an n of at most 53

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 2000000

// solve X(X+1) = n for X
int solveXX1(int n) {
    return (sqrt(4*n + 1) - 1)/2;
}

int rectangles(int n, int m) {
    return n * m * (n+1) * (m+1) / 4;
}

int main(void) {
    int n = 0, m = 0, diff = SIZE;
    int MAX_N = solveXX1(sqrt(4 * SIZE));   // n(n+1) = ceil(sqrt(8000000)) --> n = 53
    for (int i = 1; i <= MAX_N; i++) {
        int mm1 = 4 * SIZE/(i*(i + 1));     // m(m+1) = 8000000/(n(n+1))
        int j = solveXX1(mm1);              // m(m+1) = mm1 --> m^2 + m - mm1 = 0 --> m = 1/2 (sqrt(4mmi + 1) - 1)
        int nextDiff = abs(SIZE - rectangles(i, j));
        if (nextDiff < diff) {
            n = i;
            m = j;
            diff = nextDiff;
        }
    }
    printf("%d x %d = %d, with %d rectangles.\n", n, m, n * m, rectangles(n, m));
}