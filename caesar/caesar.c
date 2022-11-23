#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, string argv[])
{
if(argc!=2)
{
    printf("Usage: ./caesar key\n");
    return 1;
}

else if(isdigit(argv[1]))
{
    printf("%s\n",argv[1]);
}
}