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
        int c = plaintext[i];
        if(islower(c))
        {
            
        }
    }


    return 0;
}
else
{
    printf("Usage: ./caesar key\n");
    return 1;
}

}