# TODO
from cs50 import get_int



def main():
    number = int(input("Number: "))


    sum = 0
    while(number > 0):
        digit = number % 10
        sum = sum + digit
        number = number / 100
    print(sum)



if __name__ == "__main__":
    main()



