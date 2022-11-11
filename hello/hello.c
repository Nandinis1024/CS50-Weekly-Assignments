#include<stdio.h>
int main(void)
{   char name[50];
    printf("what is your name?\n");
    gets(name);
    printf("hello %s ",name);
}