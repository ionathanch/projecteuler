import math

permutation = []
digits = range(0, 10)
position = 999999
while (len(digits)):
    width = math.factorial(len(digits) - 1)
    permutation.append(digits.pop(position / width))
    position %= width
print int(''.join(map(str, permutation)))
