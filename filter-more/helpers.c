#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg = ((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed)/3);
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width/2); j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][(width-1)-j];
            image[i][(width-1)-j] = temp;

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int redsum, bluesum, greensum;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            redsum = 0, bluesum = 0, greensum = 0;
            for (int x = i-1; x <= i+1; x++)
            {


                for (int y = j-1; y <= j+1; y++)
                {
                    if (x!=i && y!=j)
                    {
                         redsum = redsum + image[x][y].rgbtRed;
                         bluesum = bluesum + image[x][y].rgbtBlue;
                         greensum = greensum + image[x][y].rgbtGreen;

                    }


                }
            }
            int redavg = (redsum)/((i*j)-1);
            int blueavg = (bluesum)/((i*j)-1);
            int greenavg = (greensum)/((i*j)-1);
            image[i][j].rgbtRed = redavg;
            image[i][j].rgbtBlue = blueavg;
            image[i][j].rgbtGreen = greenavg;


        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
