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
    int i=1,j=1;
    for( ;i<=height;i++){
      for( ;j<=(height-i)+1;j++){
        printf(" ");
      }
      printf("\n");
    }
    for( ;i<=height;i++){
      for(;j<=i;j++){
        printf("#");
      }
      printf("\n");
    }

}