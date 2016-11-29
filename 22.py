import csv

sorted_names_list = sorted(list(csv.reader(open('p022_names.txt', 'rb')))[0])
print sum(map(lambda name: (sorted_names_list.index(name) + 1) * sum(map(lambda char: ord(char) - 64, name)), sorted_names_list))

