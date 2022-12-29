import csv
filename ="C:\Users\nandi\2018m.csv"
with open(filename) as file:
    reader = csv.DictReader(file)
    for row in reader:
        print(row)



