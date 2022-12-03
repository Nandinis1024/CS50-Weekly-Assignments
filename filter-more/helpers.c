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
     RGBTRIPLE temp[height][width];

    // Make copy of image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    // Sobel Operator matrices for Gx and Gy
    int kernel_Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int kernel_Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // Iterate through the height or also known as each row
    for (int i = 0; i < height; i++)
    {
        // Iterate through the width or also known as each pixel/column
        for (int j = 0; j < width; j++)
        {
            // Initialize values for weighted sums in the x direction
            double gx_blue = 0;
            double gx_green = 0;
            double gx_red = 0;
            // Initialize values for weighted sums in the y direction
            double gy_blue = 0;
            double gy_green = 0;
            double gy_red = 0;
            // Counter to detect what row of the 3x3 the loop is iterating
            int row = 0;

            // Loop to check the surrounding pixels within 1 row
            for (int k = i - 1; k <= i + 1; k++)
            {
                // Counter to detect what column of the 3x3 grid the loop is iterating
                int column = 0;
                // Loop to check the surrounding pixels within 1 column
                for (int l = j - 1; l <= j + 1; l++)
                {
                    // Only adds pixels that are within the image boundaries
                    if (k >= 0 && l >= 0 && k < height && l < width)
                    {
                        // Calculate Gx
                        gx_blue += (kernel_Gx[row][column] * temp[k][l].rgbtBlue);
                        gx_green += (kernel_Gx[row][column] * temp[k][l].rgbtGreen);
                        gx_red += (kernel_Gx[row][column] * temp[k][l].rgbtRed);
                        // Calculate Gy
                        gy_blue += (kernel_Gy[row][column] * temp[k][l].rgbtBlue);
                        gy_green += (kernel_Gy[row][column] * temp[k][l].rgbtGreen);
                        gy_red += (kernel_Gy[row][column] * temp[k][l].rgbtRed);
                    }
                    column++;
                }
                row++;
            }
            // Combine Gx and Gy
            int sobel_blue = round(sqrt(pow(gx_blue, 2) + pow(gy_blue, 2)));
            int sobel_green = round(sqrt(pow(gx_green, 2) + pow(gy_green, 2)));
            int sobel_red = round(sqrt(pow(gx_red, 2) + pow(gy_red, 2)));

            // Set the new colour values for the iterated pixel and cap at 255 if necessary
            image[i][j].rgbtBlue = (sobel_blue > 255) ? 255 : sobel_blue;
            image[i][j].rgbtGreen = (sobel_green > 255) ? 255 : sobel_green;
            image[i][j].rgbtRed = (sobel_red > 255) ? 255 : sobel_red;
        }
    }

    return;
}
