import csv
import sys


profiles = []
file = "/workspaces/114241516/dna/databases/small.csv"
with open(file) as database:
        reader_obj = csv.reader(database)


        for row in reader_obj[1:]:
            # Add person to profiles
            profiles.append(row)

print (profiles)
