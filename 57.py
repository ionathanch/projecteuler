numerator = 3
denominator = 2
count = 0
for i in range(0, 1001):
    newDen = numerator + denominator
    newNum = newDen + denominator
    numerator = newNum
    denominator = newDen
    if len(str(numerator)) > len(str(denominator)):
        count += 1
print count
