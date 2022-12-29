# TODO
from cs50 import get_int

while True:
    height = get_int("height: ")
    if (height > 0 and height < 9):
        break

for row in range(1, height + 1):
    for col in range(height - row):
        print(" ", end="")

    for col in range(row):
        print("#", end="")

    for col in range(2):
        print(" ", end="")

    for col in range(row):
        print("#", end="")

    print()