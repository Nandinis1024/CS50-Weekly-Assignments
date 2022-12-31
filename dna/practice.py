import csv
import sys


database = []
filename1 = "/workspaces/114241516/dna/databases/small.csv"
with open(filename1) as file:
    reader = csv.DictReader(file)
    for row in reader:
        database.append(row)
print(database)
