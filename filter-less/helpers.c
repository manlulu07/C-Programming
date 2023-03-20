#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //go through the rows
    for (int i = 0; i < height; i++)
    {
        //go through the columns
        for (int j = 0; j < width ; j++)
        {
            //change to floats
            float Red = image[i][j].rgbtRed;
            float Green = image[i][j].rgbtGreen;
            float Blue = image[i][j].rgbtBlue;

            //calculate average
            int average = round((Red + Green + Blue) / 3);
            image[i][j].rgbtRed =  image[i][j].rgbtGreen =  image[i][j].rgbtBlue = average;

        }
    }
    return;
}



// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //go through columns
    for (int i = 0; i < height; i++)
    {
        //go through the rows
        for (int j = 0; j < width; j++)
        {
            //change to floats
            float Red = image[i][j].rgbtRed;
            float Green = image[i][j].rgbtGreen;
            float Blue = image[i][j].rgbtBlue;

            //calculate sepia Red
            int sepiaRed = round(0.393 * Red + 0.769 * Green + 0.189 * Blue);
            int sepiaGreen = round(0.349 * Red + 0.686 * Green + 0.168 * Blue);
            int sepiaBlue = round(0.272 * Red + 0.534 * Green + 0.131 * Blue);


            //assign each sepia colour value
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if ( sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            //final colour

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;

        }
    }
    return;
}



// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //go through the columns
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;

        }
    }

    return;
}




// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //make image copy
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        //go through the columns
        for (int j = 0; j < width ; j++)
        {
            temp[i][j] = image[i][j];

        }
    }
    for (int i = 0; i < height; i++)
    {
        //go through the columns
        for (int j = 0; j < width ; j++)
        {
           int totalRed, totalGreen, totalBlue;
           totalRed = totalGreen = totalBlue = 0;
           float counter = 0.00;

            //find surrounding pixels
            for (int x = -1; x < 2; x++)\
            {
               for (int y = -1; y < 2; y++)
               {
                   int currentX = i + x;
                   int currentY = j + y;

                   //check for validity
                   if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width -1))
                   {
                       continue;
                   }

                //Get values
                   totalRed += image[currentX][currentY].rgbtRed;
                   totalGreen += image[currentX][currentY].rgbtGreen;
                   totalBlue += image[currentX][currentY].rgbtBlue;

                   counter++;
               }
            //calculate avarage
               temp[i][j].rgbtRed = round(totalRed / counter);
               temp[i][j].rgbtGreen = round(totalGreen / counter);
               temp[i][j].rgbtBlue = round(totalBlue / counter);
            }


        }
    }
    // copy values to image
    for (int i = 0; i < height; i++)
    {
        //go through the columns
        for (int j = 0; j < width ; j++)
        {
           image[i][j].rgbtRed = temp[i][j].rgbtRed;
           image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
           image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}
