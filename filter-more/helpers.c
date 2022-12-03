#include "helpers.h"
#include "math.h"

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
    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width; j++)
        {
            // Variable that counts how many numbers added to arrive at the sum
            int count = 0;

            // Sum variables for each colour
            double sum_blue = 0;
            double sum_green = 0;
            double sum_red = 0;

            // Loop to check the surrounding pixels within 1 column and 1 row
            for (int k = i - 1; k <= i + 1; k++)
            {
                for (int l = j - 1; l <= j + 1; l++)
                {
                    // Only adds pixels that are within the image boundaries
                    if (k >= 0 && l >= 0 && k < height && l < width && k!=i && l!=j)
                    {
                        sum_blue += image[k][l].rgbtBlue;
                        sum_green += image[k][l].rgbtGreen;
                        sum_red += image[k][l].rgbtRed;
                        count++;
                    }
                }
            }
            // Use the averages from the surrounding pixels and set the new colour values for the iterated pixel
            image[i][j].rgbtBlue = round(sum_blue / count);
            image[i][j].rgbtGreen = round(sum_green / count);
            image[i][j].rgbtRed = round(sum_red / count);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int gx[3][3] = {{-1,0,1},{-2,0,2},{-1,0,1}};
    int gy[3][3] = {{-1,-2,-2},{0,0,0},{1,2,1}};
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double sum_blue_x = 0;
            double sum_green_x = 0;
            double sum_red_x = 0;

            double sum_blue_y = 0;
            double sum_green_y = 0;
            double sum_red_y = 0;

            for (int x = i-1; x <= i+1; x++)
            {
                for (int y = j-1; y <= j+1; y++)
                {
                    if (x >=0 && y >= 0 && x < height && y < width)
                    {
                        for (int m = 0; m < 3; m++)
                        {
                            for (int n = 0; n < 3; n++)
                            {
                                sum_blue_x += image[x][y].rgbtBlue * gx[m][n];
                                sum_green_x += image[x][y].rgbtGreen * gx[m][n];
                                sum_red_x += image[x][y].rgbtRed * gx[m][n];

                                sum_blue_y += image[x][y].rgbtBlue * gy[m][n];
                                sum_green_y += image[x][y].rgbtGreen * gy[m][n];
                                sum_red_y += image[x][y].rgbtRed * gy[m][n];



                            }
                        }
                    }
                }
            }



            image[i][j].rgbtBlue = pow((pow(sum_blue_x, 2)+pow(sum_blue_y, 2)), 0.5);
            image[i][j].rgbtGreen = pow((pow(sum_green_x, 2)+pow(sum_green_y, 2)), 0.5) ;
            image[i][j].rgbtRed = pow((pow(sum_red_x, 2)+pow(sum_red_y, 2)), 0.5);




        }
    }

    return;
}
