#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float blue = image[i][j].rgbtBlue
            float green = image[i][j].rgbtGreen;
            float red =
            int avg = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed)/3);
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


            double sum_blue = 0;
            double sum_green = 0;
            double sum_red = 0;


            for (int k = i - 1; k <= i + 1; k++)
            {
                for (int l = j - 1; l <= j + 1; l++)
                {

                    if (k >= 0 && l >= 0 && k < height && l < width && k!=i && l!=j)
                    {
                        sum_blue += image[k][l].rgbtBlue;
                        sum_green += image[k][l].rgbtGreen;
                        sum_red += image[k][l].rgbtRed;
                        count++;
                    }
                }
            }

            image[i][j].rgbtBlue = round(sum_blue / count);
            image[i][j].rgbtGreen = round(sum_green / count);
            image[i][j].rgbtRed = round(sum_red / count);
        }
    }
    return;
}


void edges(int height, int width, RGBTRIPLE image[height][width])
{
     RGBTRIPLE temp[height][width];


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }


    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};


    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width; j++)
        {

            double gx_blue = 0;
            double gx_green = 0;
            double gx_red = 0;

            double gy_blue = 0;
            double gy_green = 0;
            double gy_red = 0;

            int row = 0;


            for (int k = i - 1; k <= i + 1; k++)
            {

                int column = 0;

                for (int l = j - 1; l <= j + 1; l++)
                {

                    if (k >= 0 && l >= 0 && k < height && l < width)
                    {

                        gx_blue += (gx[row][column] * temp[k][l].rgbtBlue);
                        gx_green += (gx[row][column] * temp[k][l].rgbtGreen);
                        gx_red += (gx[row][column] * temp[k][l].rgbtRed);

                        gy_blue += (gy[row][column] * temp[k][l].rgbtBlue);
                        gy_green += (gy[row][column] * temp[k][l].rgbtGreen);
                        gy_red += (gy[row][column] * temp[k][l].rgbtRed);
                    }
                    column++;
                }
                row++;
            }

            int blue = round(sqrt(pow(gx_blue, 2) + pow(gy_blue, 2)));
            int green = round(sqrt(pow(gx_green, 2) + pow(gy_green, 2)));
            int red = round(sqrt(pow(gx_red, 2) + pow(gy_red, 2)));


            if (red > 255)
            {
                red = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            if (blue > 255)
            {
                blue = 255;
            }

            image[i][j].rgbtRed = red;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtBlue = blue;
        }
    }

    return;
}
