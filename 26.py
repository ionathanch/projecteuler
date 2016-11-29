def numOfRepetends(n):
    if not n:
        return 0

    remainders = []
    dividend = 10
    while dividend != 0:
        if dividend in remainders:
            return len(remainders) - remainders.index(dividend)
        else:
            remainders.append(dividend)
            dividend = (dividend % n) * 10
    return 0

repetendLengths = map(numOfRepetends, range(0, 1000))
maxRepetend = repetendLengths.index(max(repetendLengths))
print maxRepetend
