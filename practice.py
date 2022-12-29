import csv
filename = "aapl.csv"
with open(filename) as file:
    reader = csv.DictReader(file)
    for row in reader:
        print(row)



