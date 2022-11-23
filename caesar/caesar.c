#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, string argv[])
{
if(argc != 2)
{
    printf("Usage: ./caesar key\n");
    return 1;
}
else if()
else
{
    int key = atoi(argv[1]);
    string plaintext = get_string("plaintext:  ");
    printf("ciphertext: ");
    int length = strlen(plaintext);
    for(int i = 0; i < length; i++)
    {
        char c = plaintext[i];
        if(islower(c))
        {
            printf("%c",(((c-'a')+ key)%26)+'a');

        }
        else if(isupper(c))
        {
            printf("%c",(((c-'A')+ key)%26)+'A');

        }
        else
        {
            printf("%c",c);
        }
    }
    printf("\n");


    return 0;

}

}