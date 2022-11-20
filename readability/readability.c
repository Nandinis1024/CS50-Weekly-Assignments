#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
string text = get_string("text: ");
//count the number of letters
int letters = count_letters(text);
printf("letters: %d\n",letters);
//count the number of words
int words = count_words(text);
printf("words: %d\n",words);
//count the number of sentences
int sentences = count_sentences(text);
printf("sentences: %d\n",sentences);

//formula
int index = 0.0588 * ((letters/words)*100) - 0.296 * ((sentences/words)*100) - 15.8;
printf("Grade: %d\n",index);
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
    int count=0;
int length = strlen(text);
for(int i=0;i<length;i++)
{   char c=text[i];
   if(c==' ')
   {
    count++;
   }
   else
   {
    continue;
   }
}
return count+1;

}
int count_sentences(string text)
{
    //this function counts and returns the number of sentences to the main function
    int count=0;
int length = strlen(text);
for(int i=0;i<length;i++)
{   char c=text[i];
   if(c == '.'||c == '!'||c == '?')
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