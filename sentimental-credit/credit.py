# TODO
from cs50 import get_int



def main():
    i = 1
    sum1 = 0
    sum2 = 0
    number = int(input("Number: "))
    while(number > 0):
        if (i % 2 != 0):
            digit1 = number % pow(10,i)
            sum1 = sum1 + digit1

        elif(i % 2 == 0):
            digit2 = number % pow(10,i)
            sum2 = sum2 + digit2

        i = i + 1
        number = number %  10

    print(sum1)
    print(sum2)

















if __name__ == "__main__":
    main()



