# TODO
from cs50 import get_int



def main():

    digit1 = 0
    digit2 = 0
    num_digits = 0
    sum_of_double_odds = 0
    sum_of_evens = 0
    cc_number = get_int("Number: ")

    while cc_number > 0:
        digit2 = digit1
        digit1 = cc_number % 10

        if num_digits % 2 == 0:
            sum_of_evens += digit1
        else:
            multiple = 2 * digit1
            sum_of_double_odds += (multiple // 10) + (multiple % 10)

        cc_number //= 10
        num_digits += 1

    print(sum_of_evens)
    print(sum_of_double_odds)





















if __name__ == "__main__":
    main()



