#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]) {
    char* num = malloc (sizeof (char) * 1);
    num[0] = 1;

    int len = 1;
    for (int i = 1; i <= 1000; i++) {
        if (num[len - 1] >= 5) {
            num = realloc (num, sizeof (char) * ++len);
            num[len - 1] = 0;
        }
        
        int carry = 0;
        for (int j = 0; j < len; j++) {
            int new_carry = (num[j] * 2) / 10;
            num[j] = carry + (num[j] * 2) % 10;
            carry = new_carry;
        }
    }
    
    int sum = 0;
    printf("Length: %d\n", len);
    for (int i = 0; i < len; i++) {
        printf("%d", num[len - i - 1]);
        sum += num[i];
    }
    free (num);

    printf("\nSum: %d\n", sum);
}
