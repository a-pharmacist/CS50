#include <math.h>

#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    float half = width / 2;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < half; j++)
        {
            int tmp_rgbtRed = image[i][j].rgbtRed;
            int tmp_rgbtGreen = image[i][j].rgbtGreen;
            int tmp_rgbtBlue = image[i][j].rgbtBlue;

            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;

            image[i][width - j - 1].rgbtRed = tmp_rgbtRed;
            image[i][width - j - 1].rgbtGreen = tmp_rgbtGreen;
            image[i][width - j - 1].rgbtBlue = tmp_rgbtBlue;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE image_copy[height][width];

    // Create a copy
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image_copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float k = 0;
            int sumRed = 0;
            int sumGreen = 0;
            int sumBlue = 0;

            // Pixel 0
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                sumRed += image_copy[i - 1][j - 1].rgbtRed;
                sumGreen += image_copy[i - 1][j - 1].rgbtGreen;
                sumBlue += image_copy[i - 1][j - 1].rgbtBlue;
                k++;
            }

            // Pixel 1
            if (i - 1 >= 0)
            {
                sumRed += image_copy[i - 1][j].rgbtRed;
                sumGreen += image_copy[i - 1][j].rgbtGreen;
                sumBlue += image_copy[i - 1][j].rgbtBlue;
                k++;
            }

            // Pixel 2
            if (i - 1 >= 0 && j + 1 < width)
            {
                sumRed += image_copy[i - 1][j + 1].rgbtRed;
                sumGreen += image_copy[i - 1][j + 1].rgbtGreen;
                sumBlue += image_copy[i - 1][j + 1].rgbtBlue;
                k++;
            }

            // Pixel 3
            if (j - 1 >= 0)
            {
                sumRed += image_copy[i][j - 1].rgbtRed;
                sumGreen += image_copy[i][j - 1].rgbtGreen;
                sumBlue += image_copy[i][j - 1].rgbtBlue;
                k++;
            }

            // Pixel 4 (itself)
            sumRed += image_copy[i][j].rgbtRed;
            sumGreen += image_copy[i][j].rgbtGreen;
            sumBlue += image_copy[i][j].rgbtBlue;
            k++;

            // Pixel 5
            if (j + 1 < width)
            {
                sumRed += image_copy[i][j + 1].rgbtRed;
                sumGreen += image_copy[i][j + 1].rgbtGreen;
                sumBlue += image_copy[i][j + 1].rgbtBlue;
                k++;
            }

            // Pixel 6
            if (i + 1 < height && j - 1 >= 0)
            {
                sumRed += image_copy[i + 1][j - 1].rgbtRed;
                sumGreen += image_copy[i + 1][j - 1].rgbtGreen;
                sumBlue += image_copy[i + 1][j - 1].rgbtBlue;
                k++;
            }

            // Pixel 7
            if (i + 1 < height)
            {
                sumRed += image_copy[i + 1][j].rgbtRed;
                sumGreen += image_copy[i + 1][j].rgbtGreen;
                sumBlue += image_copy[i + 1][j].rgbtBlue;
                k++;
            }

            // Pixel 8
            if (i + 1 < height && j + 1 < width)
            {
                sumRed += image_copy[i + 1][j + 1].rgbtRed;
                sumGreen += image_copy[i + 1][j + 1].rgbtGreen;
                sumBlue += image_copy[i + 1][j + 1].rgbtBlue;
                k++;
            }

            int averageRed = round(sumRed / k);
            int averageGreen = round(sumGreen / k);
            int averageBlue = round(sumBlue / k);

            image[i][j].rgbtRed = averageRed;
            image[i][j].rgbtGreen = averageGreen;
            image[i][j].rgbtBlue = averageBlue;
        }
    }
}