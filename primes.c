#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/*
 *  unmemoized version of isPrime
 *  runs in O(sqrt(n))
 *
 */
bool isPrime(long n) {
    if (n == 0 || n == 1)
        return false;

    long sqrtn = (long) sqrt (n);
    for (long i = 2; i <= sqrtn; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

/*
 *  memoized version of isPrime
 *  primes: list of primes < n
 *  runs in O(sqrt(n)/ln(n))
 *
 */
bool isPrimeMem(long n, long* primes) {
    if (n == 0 || n == 1)
        return false;
    if (n == 2 || n == 3)
        return true;

    long sqrtn = (long) sqrt (n);
    long i = 0;
    while (primes[i] <= sqrtn) {
        if (n % primes[i++] == 0)
            return false;
    }
    return true;
}

/*
 *  calculates primes <= n using dynamic programming
 *
 *  n: non-negative int
 *  primes_ptr: pointer to array of primes <= n
 *  primesTable_ptr: pointer to array of size n+1
 *      where the 0-based ith element is true if i is prime
 *  returns: number of primes in *primes_ptr
 *
 *  N.B. numOfPrimesUpper is an upper-bound of
 *      the prime-counting function, given by
 *      n/ln(n) * 1.25506
 *
 *  runs in O(n * sqrt(n)/ln(n)) (not a tight bound)
 *
 */

long listOfPrimes(long n, long** primes_ptr, bool** primesTable_ptr) {
    *primesTable_ptr = calloc (n + 1, sizeof (bool));

    if (n == 0 || n == 1) {
        *primes_ptr = malloc (0);
        return 0;
    }

    long numOfPrimesUpper = (long) (n/log(n) * 1.25506);
    *primes_ptr = malloc (sizeof (long) * numOfPrimesUpper);
    long numOfPrimes = 0;
    for (long i = 0; i <= n; i++) {
        if (isPrimeMem(i, *primes_ptr)) {
            (*primes_ptr)[numOfPrimes] = i;
            (*primesTable_ptr)[i] = true;
            numOfPrimes++;
        }
    }
    if (numOfPrimes < numOfPrimesUpper) {
        long* tmp = realloc (*primes_ptr,
                             sizeof (long) * numOfPrimes);
        if (tmp != NULL)
            *primes_ptr = tmp;
    }

    return numOfPrimes;
}

/*
 *  calculates primes <= n are prime using the sieve of Eratosthenes
 *
 *  runs in O(n ln(ln(n))) apparently
 *
 */
void sieveOfEratosthenes(int n, bool** primesTable_ptr) {
    *primesTable_ptr = malloc (sizeof (bool) * (n + 1));
    for (int i = 0; i <= n; i++)
        (*primesTable_ptr)[i] = true;

    (*primesTable_ptr)[0] = false;
    (*primesTable_ptr)[1] = false;

    int sqrtn = (int) sqrt (n);
    for (int i = 0; i <= sqrtn; i++) {
        if ((*primesTable_ptr)[i] == true) {
            for (int j = i*2; j <= n; j += i) {
                (*primesTable_ptr)[j] = false;
            }
        }
    }
}
