import csv
import sys

file = "/workspaces/114241516/dna/databases/small.csv"
with open(file) as database:
        reader = csv.DictReader(database)

        STRs = reader.fieldnames[1:]
        for row in reader:
            # Add person to profiles
            profiles.append(row)


