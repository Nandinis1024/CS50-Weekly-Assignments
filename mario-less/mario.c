#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    printf("enter height:\n");
    scanf("%d",&height);
    while(true){
    if(height<1||height>8){

      printf("OOPS WRONG INPUT,enter height AGAIN:\n");
      scanf("%d",&height);

    }

    else{
       break;
    }
    }
    printf("There you go Maro!\n");
   for(int i=1;i<=height;i++){
    for(int j=1;j<=(height-i);j++){
      printf(" ");
    }
    int k=1;
    for(;k<=i;k++){
      printf("#");
    }
    printf("\n");


   }

}