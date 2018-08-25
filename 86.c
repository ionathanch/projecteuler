#include <math.h>
#include <stdio.h>

int main(void) {
    int M = 100, count = 2060;
    while(count < 1000000) {
        M++;
        for (int i = 1; i <= M; i++) {
            for (int j = i; j <= M; j++) {
                double path = sqrt((i + j) * (i + j) + M * M);
                if (path == floor(path)) {
                    count++;
                }
            }
        }
    }
    printf("M = %d has %d distinct cuboids\n", M, count);
}