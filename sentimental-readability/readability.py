# TODO
from cs50 import get_string
def main():
    text = get_string("text: ")
    print(count_letters(text))
    print(count_words(text))
    print(count_sentences(text))

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
    count  = 0
    for c in text:
        if c == '.' or c == '!' or c == '?':
            count = count + 1
        else:
            continue

    return count



if __name__ == "__main__":
    main()