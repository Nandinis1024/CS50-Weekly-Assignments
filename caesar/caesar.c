#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
if(argc!=2||isdigit(argv[1])==0)
{
    printf("Usage: ./caesar key\n");
    return 1;
}
else
{
    printf("%s\n",argv[1]);
}
}