#include <stdio.h>
#include <stdlib.h>

int main (int argc, int argv[]) {
    char* prevfib = calloc (1000, sizeof (int));
    char* currfib = calloc (1000, sizeof (int));
    prevfib[0] = 1;
    currfib[0] = 1;
    int index = 2;

    while (1) {
        index++;
	char* temp = prevfib;
	prevfib = currfib;
	currfib = calloc (1000, sizeof (int));
	
	char carry = 0;
	for (int i = 0; i < 1000; i++) {
            char sum = temp[i] + prevfib[i] + carry;
	    currfib[i] = sum % 10;
	    carry = sum / 10;
	}
	free (temp);

        if (currfib[999] != 0)
	    break;
    }

    printf ("%d\n", index);
}
