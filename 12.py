import math

def ithTriangularNum(i):
    return 0.5*i*(i+1)

def numOfFactors(n):
    s = int(math.sqrt(n))
    factors = 0
    for j in range(1, s):
        if n % j == 0:
            factors += 1
    return factors*2

factors = 0
i = 1
n = ithTriangularNum(i)
while factors <= 500:
    i += 1
    n = ithTriangularNum(i)
    factors = numOfFactors(n)

print i, n, factors