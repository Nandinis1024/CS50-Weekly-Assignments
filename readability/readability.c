#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_letters(string text);



int main(void)
{
string text = get_string("text: ");
//count the number of letters
int letters = count_letters(text);
printf("%d\n",letters);

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