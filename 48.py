sum = 0 
for i in range (1, 1001):
    sum = sum + i ** i
print sum % 10000000000
