#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    printf("enter height:\n");
    scanf("%d",&height);
    while(true){
    if(height<1||height>8){

      printf("enter height:\n");
      scanf("%d",&height);

    }

    else{
       break;
    }
    }
    for(int row=1;row<=height;row++){
      for(int col=height;col>=row;col--){

      }
    }
}