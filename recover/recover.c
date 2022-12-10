#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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
if(file == NULL)
{
    
}
typedef uint8_t BYTE;
BYTE buffer[BLOCK_SIZE];
while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE)
{
    if(buffer[0]==0xff && buffer[1] == 0xd8 && buffer[2] == 0Xff && (buffer[3] & 0Xf0) == 0Xe0 )
    {

    }


}
