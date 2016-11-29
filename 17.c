#include <stdio.h>
#include <stdlib.h>

int nums[1001];
int hundred = 7;
int and = 3;

void assign_base_nums () {
    nums[0] = 0; // placeholder
    nums[1] = 3; // one
    nums[2] = 3; // two
    nums[3] = 5; // three
    nums[4] = 4; // four
    nums[5] = 4; // five
    nums[6] = 3; // six
    nums[7] = 5; // seven
    nums[8] = 5; // eight
    nums[9] = 4; // nine

    nums[10] = 3; // ten
    nums[11] = 6; // eleven
    nums[12] = 6; // twelve
    nums[13] = 8; // thirteen
    nums[14] = 8; // fourteen
    nums[15] = 7; // fifteen
    nums[16] = 7; // sixteen
    nums[17] = 9; // seventeen
    nums[18] = 8; // eighteen
    nums[19] = 8; // nineteen

    nums[20] = 6; // twenty
    nums[30] = 6; // thirty
    nums[40] = 5; // forty
    nums[50] = 5; // fifty
    nums[60] = 5; // sixty
    nums[70] = 7; // seventy
    nums[80] = 6; // eighty
    nums[90] = 6; // ninety 

    nums[1000] = 11; // one thousand
}

void assign_composite_nums () {
    // twenty to ninety-nine
    for (int i = 2; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            nums[10*i + j] = nums[10*i] + nums[j];
        }
    }

    // one hundred to nine hundred and ninety-nine
    for (int i = 1; i <= 9; i++) {
        nums[100*i] = nums[i] + hundred;
        for (int j = 1; j <= 99; j++) {
            nums[100*i + j] = nums[100*i] + and + nums[j];
        }
    }
}

void sum_all_nums() {
    int sum = 0;
    for (int i = 1; i <= 1000; i++) {
        sum += nums[i];
    }
    printf("%d\n", sum);
}

int main (int argc, char* argv[]) {
    assign_base_nums();
    assign_composite_nums();
    sum_all_nums();
}
