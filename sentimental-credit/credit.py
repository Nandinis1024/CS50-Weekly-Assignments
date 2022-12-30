# TODO
from cs50 import get_int



def main():

    digit1 = 0
    i = 0
    sum_of_double_odds = 0
    sum_of_evens  = 0
    number = get_int("Number: ")

    while number > 0:
        digit1 = number % 10

        if i % 2 == 0:
            sum_of_evens += digit1
        else:
            multiple = 2 * digit1
            sum_of_double_odds += (multiple // 10) + (multiple % 10)

        number //= 10
        i += 1

   





















if __name__ == "__main__":
    main()



