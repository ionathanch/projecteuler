largest = 0
for a in range(10, 100):
    for b in range(10, 100):
        largest = max(largest, sum(map(int, list(str(a**b)))))
print largest
