# TODO

while True:
    height = int(input("Height: "))
    if(height > 0 and height < 9 and height.isnumeric()):
        break



for rows in range(1,height + 1):
    for col in range(height - rows):
        print(" ",end="")


    for col in range(rows):
        print("#",end="")


    for col in range(2):
        print(" ",end="")

    for col in range(rows):
        print("#",end="")
    print()


















