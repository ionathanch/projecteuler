#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define GO   0
#define JAIL 10
#define G2J  30

#define CC1  2
#define CC2  17
#define CC3  33

#define CH1  7
#define CH2  22
#define CH3  36

#define C1   11
#define E3   24
#define H2   39

#define R1   5
#define R2   15
#define R3   25

#define U1   12
#define U2   28

int CC[2] = {GO, JAIL};
int CH[6] = {GO, JAIL, C1, E3, H2, R1};

unsigned long long freq[40] = {0};
int doubleRolls = 0;
int position = GO;
int communityChestIndex = 0;
int chanceIndex = 0;

void moveToSquare(int square) {
    position = square;
    freq[square]++;
}

void communityChest() {
    communityChestIndex = ++communityChestIndex % 16;
    if (communityChestIndex == 1 || communityChestIndex == 2) {
        moveToSquare(CC[communityChestIndex - 1]);
    } else {
        moveToSquare(position);
    }
}

void chance() {
    chanceIndex = ++chanceIndex % 16;
    if (chanceIndex >= 1 && chanceIndex <= 6) {
        moveToSquare(CC[chanceIndex - 1]);
    } else if (chanceIndex == 7 || chanceIndex == 8) {
        if (position == CH1) {
            moveToSquare(R2);
        } else if (position == CH2) {
            moveToSquare(R3);
        } else {
            moveToSquare(R1);
        }
    } else if (chanceIndex == 9) {
        if (position == CH2) {
            moveToSquare(U2);
        } else {
            moveToSquare(U1);
        }
    } else if (chanceIndex == 10) {
        position -= 3;
        if (position == CH3) {
            communityChest();
        } else {
            moveToSquare(position);
        }
    } else {
        moveToSquare(position);
    }
}

int main(void) {
    srand(time(NULL));

    for (unsigned long long i = 0; i < 20000000; i++) {
        int die1 = (rand() % 4) + 1;
        int die2 = (rand() % 4) + 1;
        int dice = die1 + die2;

        if (die1 == die2) {
            doubleRolls = ++doubleRolls % 3;
            if (doubleRolls == 0) {
                moveToSquare(JAIL);
                continue;
            }
        }

        position = (position + dice) % 40;
        if (position == G2J) {
            moveToSquare(JAIL);
        } else if (position == CC1 || position == CC2 || position == CC3) {
            communityChest();
        } else if (position == CH1 || position == CH2 || position == CH3) {
            chance();
        } else {
            moveToSquare(position);
        }
    }
    
    for (int i = 0; i < 40; i++) {
        printf("%02d: %llu\n", i, freq[i]);
    }
}