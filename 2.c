#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    long prevfib = 1;
    long currfib = 2;
    long evenfibs = 2;
    while (currfib < 4000000) {
        long fib = currfib + prevfib;
        prevfib = currfib;
        currfib = fib;
        if (currfib % 2 == 0) {
            evenfibs += currfib;
        } 
    }
    printf("%d\n", evenfibs);
    return 0;
}
