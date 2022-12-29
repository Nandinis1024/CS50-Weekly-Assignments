# TODO
from  cs50 import get_int

while True:
    try:
        # ask for input
        height = int(input("Height: "))

        # make sure height is greater than 0 and less than or equal to 8
        if height >= 1 and height <= 8:
            break

        # iterate through height
        for row in range(height + 1):
            print(" " * (height - 1 - counter), end="")
            print("#" * (counter + 1), end="")
            print(" " * 2, end="")
            print("#" * (counter + 1), end="")
            print(end="\n")

    # display error message is value entered is below or above 1 and 8
    except ValueError:
        print("Please enter a number between 1 and 8. ", end="\n")



















