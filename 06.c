#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    double n = 100.0;
    double squareOfSumOfN = 0.25*n*n*(n+1)*(n+1);
    double sumOfSquareOfN = n*(n+1)*(2*n+1)/6;
    printf("%d\n", (long)(squareOfSumOfN - sumOfSquareOfN));
    return 0;
}
