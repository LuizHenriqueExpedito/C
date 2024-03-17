#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Through each line.
    for (int row = 0; row < height; row++)
    {
        // Through each column.
    for (int column = 0; column < width; column++)
     
        // Convert pixels to float.
        {
            float Red = image[row][column].rgbtRed;
            float Green = image[row][column].rgbtGreen;
            float Blue = image[row][column].rgbtBlue;

          // Find the avarege value.
            int rgbtGray = round((Red + Green + Blue) / 3);
            image[row][column].rgbtRed = image[row][column].rgbtGreen = image[row][column].rgbtBlue = rgbtGray;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Through each line.
    for (int row = 0; row < height; row++)
    {
        // Through each column.
        for (int column = 0; column < width; column++)
        {
            // Convert pixels to float.

            float originalRed = image[row][column].rgbtRed;
            float originalGreen = image[row][column].rgbtGreen;
            float originalBlue = image[row][column].rgbtBlue;

            // Formula to Sepia Efect.
            int sepiaRed = round (0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue);
            int sepiaGreen = round (0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue);
            int sepiaBlue = round (0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue);

            //Ensure we have standardized values for the sepia effect.

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255 )
            { 
                sepiaBlue = 255;
            }

            // Update elements of the array.
            image[row][column].rgbtRed = sepiaRed;
            image[row][column].rgbtGreen = sepiaGreen;
            image[row][column].rgbtBlue = sepiaBlue;

        }   
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width / 2; column++)

        // Pointers.
        {
            RGBTRIPLE temp = image [row][column];  
            image [row][column] = image[row][width - column - 1];
            image[row][width - column - 1] = temp;     
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
        // Copy original array.
    
    RGBTRIPLE temp[height][width];
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            temp [row][column] = image[row][column];
        }
    }

    // Through each linha
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            int totalRed = 0;
            int totalGreen = 0;
            int totalBlue = 0;
            float counter = 0.00;

            // Get neighboring pixels
            for (int x = -1; x < 2; x ++)
            {
                for (int y = -1; y < 2; y ++)
                {
                    int currentX = row  + x;
                    int currentY = column + y;


        // Check if Neighboring pixels are valids.
        if (currentX < 0 || currentX > (height - 1) ||
            currentY < 0 || currentY > (height - 1))
            {
                continue;
            }

            // Get image Values.
            totalRed += image[currentX][currentY].rgbtRed;
            totalGreen += image[currentX][currentY].rgbtGreen;
            totalBlue+= image[currentX][currentY].rgbtBlue;

            counter++;
                }

            // Calculate avarege of neighboring pixels.
            temp[row][column].rgbtRed = round(totalRed / counter);
            temp[row][column].rgbtGreen = round(totalGreen / counter);
            temp[row][column].rgbtBlue = round(totalBlue / counter);

                }
            }
        }

        // Update the original array.

        for (int row = 0 ; row < height; row++)
        {
            for (int column = 0; column < width; column++)
            {
                image[row][column].rgbtRed = temp[row][column].rgbtRed;
                image[row][column].rgbtGreen = temp[row][column].rgbtGreen;
                image[row][column].rgbtBlue = temp[row][column].rgbtBlue;
            }
        }
           
            return;

    }


