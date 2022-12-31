import csv
import sys


database = []
filename1 = 
with open(filename1) as file:
    reader = csv.DictReader(file)
    for row in reader:
        database.append(row)
print(database)
