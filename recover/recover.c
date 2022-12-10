#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    //checking the command-line arguments
    if (argc != 2)
    {
       printf("Usage: ./recover IMAGE\n");
       return 1;
    }

}
//opening the memory card
FILE*file = fopen(argv[1], "r");
