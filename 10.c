#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

long sumOfPrimes = 0;

struct node {
    long prime;
    struct node* next;
};

struct node* head = NULL;
struct node* tail = NULL;

void insertNode (long n) {
    if (head == NULL) {
        head = (struct node*) malloc (sizeof (struct node));
        head->prime = n;
        head->next = NULL;
        tail = head;
    }
    else {
        struct node* curr = (struct node*) malloc (sizeof (struct node));
        curr->prime = n;
        curr->next = NULL;
        tail->next = curr;
        tail = curr; 
    }

    sumOfPrimes += n;
}

bool isPrime (long n) {
    struct node* curr = head;
    while (curr != NULL && curr->prime <= sqrt(n)) {
        if (n % curr->prime == 0)
            return false;
        curr = curr->next;
    }
    insertNode (n);
    return true;
}

int main (int argc, char* argv[]) {
    long n = atol (argv[1]);
    for (long i = 2; i < n; i++) {
        isPrime (i);
    }

    printf("%lli\n", sumOfPrimes); 
}
