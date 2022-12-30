# TODO
from cs50 import get_int



def main():
    i = 0
    sum1 = 0
    sum2 = 0
    number = int(input("Number: "))
    while(number > 0):
        if (i % 2 == 0):
            digit1 = number % 10
            sum1 = sum1 + digit1

        elif(i % 2 == 0):
            digit2 = number % 10
            sum2 = sum2 + (2 * digit1)


        number = int(number /  10)
        i = i + 1


    print(sum1)
    print(sum2)





















if __name__ == "__main__":
    main()



