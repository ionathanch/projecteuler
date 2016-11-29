#include <stdio.h>
#include <stdlib.h>

int noleap[12] = { 31, 28, 31, 30, 31, 30,
                   31, 31, 30, 31, 30, 31 };
int leap[12] = { 31, 29, 31, 30, 31, 30,
                   31, 31, 30, 31, 30, 31 };

int main (int argc, char* argv[]) {
    int sundays = 0;
    int monmod = 0;

    for (int y = 1900; y < 2000; y++) {
        int* months;
        if (y % 4 == 0 && y % 100 != 0 || 
            y % 4 == 0 && y % 100 == 0 && y % 400 == 0)
            months = leap;
        else
            months = noleap;

        for (int m = 0; m < 12; m++) {
            monmod = (monmod + months[m]) % 7;
            if (monmod == 0 && y != 1900)
                sundays++;
        }
    }
    
    printf("%d\n", sundays);
}
