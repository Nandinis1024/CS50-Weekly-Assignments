#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<math.h>

float count_letters(string text);
float count_words(string text);
float count_sentences(string text);

int main(void)
{
string text = get_string("text: ");
//count the number of letters
float letters = count_letters(text);

//count the number of words
float words = count_words(text);

//count the number of sentences
float sentences = count_sentences(text);


//formula
float L=letters/words*100;
float S=sentences/words*100;
float index = (0.0588 * L) - (0.296 * S) - 15.8;
int grade = round(index);
if(grade<1)
{
    printf("Before grade 1\n");

}
else if(grade>16)
{
    printf("Grade 16+\n");
}
else
{
    printf("Grade  %d\n",grade);
}
}


float count_letters(string text)
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


float count_words(string text)
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
float count_sentences(string text)
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