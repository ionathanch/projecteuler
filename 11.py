import csv

table = []
with open('11.csv', 'rb') as file:
    reader = csv.reader(file, delimiter=' ')
    for row in reader:
        array = []
        for entry in row:
            array.append(int(entry))
        table.append(array)
        
horizLargest = 0
vertiLargest = 0
for i in range(0, len(table)):
    for j in range(0, len(table) - 4):
        horizLargest = max(horizLargest,
                           table[i][j] * table[i][j+1] 
                            * table[i][j+2] * table[i][j+3])
        vertiLargest = max(vertiLargest,
                           table[j][i] * table[j+1][i] * table[j+2][i] 
                            * table[j+3][i])
        
rightDiagonal = 0
for i in range(0, len(table) - 4):
    for j in range(0, len(table) - 4):
        rightDiagonal = max(rightDiagonal, table[i][j] * table[i+1][j+1]
                            * table[i+2][j+2] * table[i+3][j+3])
        
leftDiagonal = 0
for i in range(3, len(table)):
    for j in range(0, len(table) - 4):
        leftDiagonal = max(leftDiagonal, table[i][j] * table[i-1][j+1]
                           * table[i-2][j+2] * table[i-3][j+3])

print max(horizLargest, vertiLargest, rightDiagonal, leftDiagonal)