import csv
import sys

sequence = []
filename = "/workspaces/114241516/dna/sequences/1.txt"
with open(filename) as file:
    reader = csv.DictReader(file)
    for row in reader:
        sequence.append(row)
print (sequence)