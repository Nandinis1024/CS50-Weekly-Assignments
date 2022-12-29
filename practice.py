import sys
import csv
filename ="2018.csv"
with open(filename) as file:
    reader = csv.DictReader(file)
    for row in reader:
        print(row)



