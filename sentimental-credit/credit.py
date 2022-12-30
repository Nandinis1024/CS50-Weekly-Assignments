# TODO
from cs50 import get_int



def main():
    number = int(input("Number: "))


    sum1 = 0
    while(number > 0):
        digit = number % 10
        sum1 = sum1 + digit
        number = int(number / 100)
    print(sum1)



    





if __name__ == "__main__":
    main()



