#include <stdlib.h>
#include <stdio.h>
#include <math.h>

long long largestPrimeFactor(long long n) {
    if (n == 1 || n == 2)
        return n;
    long long m = sqrt(n);
    for (long long i = 2; i <= m; i++) {
        if (n % i == 0) {
            long long f1 = largestPrimeFactor(i);
            long long f2 = largestPrimeFactor(n/i);
            if (f1 > f2) 
                return f1;
            else
                return f2;
        }
    }
    return n;
}

int main(int argc, char* argv[]) {
    long long n = atoll(argv[1]);
    printf("%d\n", largestPrimeFactor(n));
    return 0;
}
