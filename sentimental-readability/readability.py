# TODO
from cs50 import get_string


def main():

    text = get_string("text: ")
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    L = letters / words * 100
    S = sentences / words * 100
    index = (0.0588 * L) - (0.296 * S) - 15.8
    grade = round(index)
    if grade < 1:

        print("Before Grade 1")

    elif grade > 16:

        print("Grade 16+")

    else:

        print("Grade" + " " + str(grade))


def count_letters(text):
    count = 0
    for c in text:
        if c.isalpha():
            count = count + 1
        else:
            continue
    return count


def count_words(text):

    count = 0
    for c in text:
        if c == ' ':
            count = count + 1

        else:
            continue
    return count + 1


def count_sentences(text):

    count = 0
    for c in text:
        if c == '.' or c == '!' or c == '?':
            count = count + 1
        else:
            continue

    return count


if __name__ == "__main__":
    main()