import csv
import sys

database = []
filename = "/workspaces/114241516/dna/databases/small.csv"
with open(filename) as file:
    reader = csv.DictReader(file)
    for row in reader:
        database.append(row)
print (database)