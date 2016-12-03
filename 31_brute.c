#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]) {
    int ways = 0;
    for (int L2 = 0; L2 <= 1; L2++) {
        for (int L1 = 0; L1 <= 2; L1++) {
            for (int p50 = 0; p50 <= 4; p50++) {
                for (int p20 = 0; p20 <= 10; p20++) {
                    for (int p10 = 0; p10 <= 20; p10++) {
                        for (int p5 = 0; p5 <= 40; p5++) {
                            for (int p2 = 0; p2 <= 100; p2++) {
                                for (int p1 = 0; p1 <= 200; p1++) {
                                    if (p1 + 2*p2 + 5*p5 + 10*p10 + 20*p20 + 50*p50 + 100*L1 + 200*L2) 
                                        ways++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    printf ("%d\n", ways);
}
