#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, string argv[])
{
if(argc == 2||isdigit(*argv[1]))
{
    int key = atoi(argv[1]);
    string plaintext = get_string("plaintext:  ");
    int length = strlen(plaintext);
    for(int i = 0; i < length; i++)
    {
        char c = plaintext[i];
        if(islower(c))
        {
           int t = (c-97)+ key;
           char c2 = t;
           printf("%c",c2);

        }
        /*else if(isupper(c))
        {

        }
        else
        {

        }*/
    }


    return 0;
}
else
{
    printf("Usage: ./caesar key\n");
    return 1;
}

}