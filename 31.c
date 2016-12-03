#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]) {
    int* ways = calloc (201, sizeof (int));
    ways[0] = 1;
    int coins[8] = { 1, 2, 5, 10, 20, 50, 100, 200 };
    for (int c = 0; c < 8; c++) {
        for (int w = 0; w <= 200; w++) {
            if (w >= coins[c]) {
                ways[w] += ways[w - coins[c]];
            }
        }
    }
    printf ("%d\n", ways[200]);
}
