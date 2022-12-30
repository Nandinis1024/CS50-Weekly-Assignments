# TODO
from cs50 import get_string
def main():
    text = get_string("text: ")
    print(count_letters(text))

def count_letters(text):
    count = 0
    for c in text:
        if c.isalpha():
            count = count + 1
        else:
            continue
    return count

#def count_words(text):
#def count_sentences(text):


if __name__ == "__main__":
    main()