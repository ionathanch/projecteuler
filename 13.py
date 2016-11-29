import csv

array = []
with open('13.csv', 'rb') as file:
    reader = csv.reader(file)
    for line in reader:
        array.append(line[0])

summa = 0
for i in range(0, 50):
    for j in range(0, 100):
        summa += int(array[j][i])
    summa *= 10
        
sumstr = str(summa)
sumlen = len(sumstr)
print sumstr[0:10]