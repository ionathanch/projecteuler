#include <stdlib.h>
#include <stdio.h>

int gcd(int v1, int v2) {
    int min;
    if (v1 < v2)
        min = v1;
    else
        min = v2;
   
    int gcd = 1;
    for (int i = 2; i <= min; i++) {
        if (v1 % i == 0 && v2 % i == 0) {
            gcd = i;
        }   
    }
    
    return gcd;
}

int main(int argc, char* argv[]) {
    int result = 1;
    for (int i = 2; i <= 20; i++) {
        printf("the gcd of %d and %d is %d\n", result, i, gcd(result, i));
        result = result * (double)i/gcd(result, i);
    }
    printf("%d\n", result);
    return 0;
}
