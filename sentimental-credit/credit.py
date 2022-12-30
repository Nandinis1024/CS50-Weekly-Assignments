# TODO
from cs50 import get_int



def main():
    i = 1
    sum1 = 0
    sum2 = 0
    number = int(input("Number: "))
    while(number > 0):
        if (i % 2 != 0):
            digit1 = number % 10
            sum1 = sum1 + digit1

        elif(i % 2 == 0):
            digit2 = number % 10
            sum2 = sum2 + (digit2 *2)


        number = int(number /  (pow(10,i)))
        i = i + 1

    

    if (((sum1 + 1) + (sum2 + 2)) % 10 != 0):
        print("INVALID")

    else:
        print("VALID")

















if __name__ == "__main__":
    main()



