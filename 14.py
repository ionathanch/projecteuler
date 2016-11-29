collatz = {}

def findStoreCollatz(n):
    if n == 1:
        collatz[1] = 1
    elif n not in collatz:
        if n % 2 == 0:
            collatz[n] = findStoreCollatz(n/2) + 1
        else:
            collatz[n] = findStoreCollatz(3*n + 1) + 1
    return collatz[n]

maxCollatzStart = 0
maxCollatzValue = 0
for i in range(1, 1000000):
    collatzVal = findStoreCollatz(i)
    if collatzVal > maxCollatzValue:
        maxCollatzValue = collatzVal
        maxCollatzStart = i
        
print maxCollatzStart, maxCollatzValue