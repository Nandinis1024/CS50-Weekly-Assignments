# TODO

while True:
    height = int(input("Height: "))
    if(height > 0 and height < 9):
        break



for rows in range(height + 1):
    for col in range(height - rows):
        print(" ",end="")


    for col in range(rows):
        print("#",end="")


    for col in range(2):
        print(" ",end="")

    for col in range(rows):
        print("#",end="")
    print()


















