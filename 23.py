def isAbundant(n):
    proper_divisors = []
    for i in range(1, n):
        if n % i == 0:
            proper_divisors.append(i)
    return sum(proper_divisors) > n

abd_arr = []
for i in range(1, 30):
    abd_arr.append(isAbundant(i))
    
is_sum = []
for i in range(1, 30):
    for j in range(1, i/2 + 1):
        if abd_arr[j+1] and abd_arr[i-j+1]:
            print i, j
            is_sum.append(i)
            break
            
print is_sum