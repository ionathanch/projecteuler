#include <time.h>
#include <stdlib.h>
#include <stdio.h>

const int GO   = 0,  JAIL = 10, G2J  = 30;    // GO/JAIL
const int CC1  = 2,  CC2  = 17, CC3  = 33;    // Community Chest
const int CH1  = 7,  CH2  = 22, CH3  = 36;    // Chance
const int R1   = 5,  R2   = 15, R3   = 25;    // Railway
const int U1   = 12, U2   = 28;               // Utilities
const int C1   = 11, E3   = 24, H2   = 39;    // other

int freq[40] = {0};
int doubleRolls = 0;
int position = GO;
int cci = 0;
int chi = 0;

int chance() {
    chi = (chi + 1) % 16;
    switch (chi) {
        case 1: return GO;
        case 2: return JAIL;
        case 3: return C1;
        case 4: return E3;
        case 5: return H2;
        case 6: return R1;
        case 7:
        case 8:
            if (position == CH1) return R2;
            if (position == CH2) return R3;
            return R1;
        case 9:
            if (position == CH2) return U2;
            return U1;
        case 10: position -= 3;
        default: return position;
    }
}

int communityChest() {
    cci = (cci + 1) % 16;
    switch (cci) {
        case 1:  return GO;
        case 2:  return JAIL;
        default: return position;
    }
}

int main(void) {
    srand(time(NULL));

    for (int i = 0; i < 40000000; i++) {
        int die1 = (rand() % 6) + 1;
        int die2 = (rand() % 6) + 1;
        position = (position + die1 + die2) % 40;
        if (die1 == die2) {
            doubleRolls = (doubleRolls + 1) % 3;
            if (doubleRolls == 0) {
                position = JAIL;
            }
        }
        if (position == G2J) {
            position = JAIL;
        }
        if (position == CH1 || position == CH2 || position == CH3) {
            position = chance();
        }
        if (position == CC1 || position == CC2 || position == CC3) {
            position = communityChest();
        }
        freq[position]++;
    }

    float sum = 0;
    for (int i = 0; i < 40; i++) {
        sum += freq[i];
    }
    for (int i = 1; i <= 3; i++) {
        int topSquare = 0, topValue = 0;
        float topFreq = 0;
        for (int j = 0; j < 40; j++) {
            if (freq[j] > topValue) {
                topSquare = j;
                topValue  = freq[j];
                topFreq   = topValue / sum;
                freq[j]   = 0;
            }
        }
        printf("#%d: %d @ %f%%\n", i, topSquare, topFreq * 100);
    }
}