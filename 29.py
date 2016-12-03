combos = []
for i in range(2, 101):
  for j in range(2, 101):
    combos.append(i**j)
    
comboset = set(combos)
print len(comboset)
