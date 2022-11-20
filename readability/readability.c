#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_letters(string text);
int count_words(string text);


int main(void)
{
string text = get_string("text: ");
//count the number of letters
int letters = count_letters(text);
//count the number of words
int words = count_words(text);

}


int count_letters(string text)
{
    //this function counts and returns the number of letters in a text to the main function
int count=0;
int length = strlen(text);
for(int i=0;i<length;i++)
{   char c=text[i];
    if(isalpha(c))
    {
      count++;
    }
    else
    {
     continue;
    }
}
return count;
}


int count_words(string text)
{
    //this function counts and returns the number of words to the main function
    for(int i=0,i<)

}