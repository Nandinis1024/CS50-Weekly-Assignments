#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    printf("enter height:\n");
    scanf("%d",&height);
    if(height<=1||height>=8){
      printf("enter height:\n");
      scanf("%d",&height);
    }
    else{
        printf("bhsd  \n");
    }
}