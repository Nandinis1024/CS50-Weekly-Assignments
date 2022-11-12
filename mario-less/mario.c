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

    
    int stored= height;
   for(int i=1;i<=stored;i++){
    for(int j=1;j<=(stored-i);j++){
      printf(" ");
    }
    int k=1;
    for(;k<=i;k++){
      printf("#");
    }
    printf("\n");


   }

}