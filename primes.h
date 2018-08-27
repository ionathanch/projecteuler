#include <stdbool.h>

bool isPrime(long n);
bool isPrimeMem(long n, long* primes);
long listOfPrimes(long n, long** primes_ptr, bool** primesTable_ptr);
void sieveOfEratosthenes(int n, bool** primesTable_ptr);
