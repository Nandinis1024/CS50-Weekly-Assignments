import csv
filename = "2019w.csv"
with open(filename) as file:
    reader = csv.DictReader(file)
    for row in reader:
        print(row)



