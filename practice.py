
import csv
teams = []

filename = "/workspaces/114241516/world-cup/2018m.csv"
with open(filename) as file:
    reader = csv.DictReader(file)
    for row in reader:
        teams.append(row)
        print(teams)



