# TODO
from  cs50 import get_int

while True:
    try:
        height = int(input("Height: "))
        width = height
        if(height > 0 and  height < 9):
            break





    for rows in range(1,height + 1):
        for col in range(width - rows):
            print(" ",end="")


        for col in range(rows):
            print("#",end="")


        for col in range(2):
            print(" ",end="")

        for col in range(rows):
            print("#",end="")
        print()

    except ValueError:
        print("Please enter a number between 1 and 8. ", end="\n")




















