import itertools as it
import gmpy2

length  = 6
repeats = 3
permupattern = [0, 0, 0, 1, 1, 1]
familysize = 8
patterns = list(set(list(it.permutations(permupattern, length))))
digits   = list(it.product(range(0, 10), repeat=length-repeats))

for pattern in patterns:
    for digit in digits:
        family = []
        for i in range(0, 10):
            numlist = []
            count = 0
            for p in pattern:
                if p:
                    numlist.append(i)
                else:
                    numlist.append(digit[count])
                    count += 1
            num = int(''.join(map(str, numlist)))
            if len(str(num)) == length:
                family.append(num)
        if family and len(filter(lambda n: gmpy2.is_prime(n), family)) == familysize: 
            print family
