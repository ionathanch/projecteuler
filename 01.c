#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    int n = atoi(argv[1])-1;
    int p = n/3;
    int q = n/5;
    int r = n/15;
    int s = 3*((p*(p+1))/2) +
            5*((q*(q+1))/2) - 
            15*((r*(r+1))/2);
    printf("%d\n", s);
    return 0;
}
