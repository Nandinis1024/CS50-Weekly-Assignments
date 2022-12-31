import csv
import sys


profiles = []
file = "/workspaces/114241516/dna/databases/small.csv"
with open(file) as database:
        reader = csv.reader(database)


        for row in reader:
            # Add person to profiles
            profiles.append(row)

print (profiles)
