#include "helpers.h"
#include "stdio.h"

//Para compilar rode: make
//Para executar rode: ./filter -b images/tower.bmp images/blurtower.bmp
//Para cada tipo de fitlro que você quer aplicar você usa as letras correspondentes: r, b, e ou g. O filtro e (edges) não foi implementado.


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    BYTE B, G, R;
    BYTE average;
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            B = image[i][j].rgbtBlue;
            G = image[i][j].rgbtGreen;
            R = image[i][j].rgbtRed;

            average = (B + G + R) / 3;

            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int midle = (width / 2) - 1;  
    int column;
    RGBTRIPLE temp; 

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j > midle)
            {
                break;
            }
            temp = image[i][j];
            column = width - j - 1;
            image [i][j] = image [i][column];
            image [i][column] = temp;
            
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    BYTE A, B, C, D, E, F, G, H, I;
    BYTE averageBlue;
    BYTE averageGreen;
    BYTE averageRed;
    RGBTRIPLE newImage[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 || i == height || j == 0 || j == width)
            {
                continue;
            }
            
            A = image[i-1][j-1].rgbtBlue;
            B = image[i-1][j].rgbtBlue;
            C = image[i-1][j+1].rgbtBlue;
            D = image[i][j-1].rgbtBlue;
            E = image[i][j].rgbtBlue;
            F = image[i][j+1].rgbtBlue;
            G = image[i+1][j-1].rgbtBlue;
            H = image[i+1][j].rgbtBlue;
            I = image[i+1][j+1].rgbtBlue;

            averageBlue = (A+B+C+D+E+F+G+H+I)/9;

            newImage[i][j].rgbtBlue = averageBlue;

            A = image[i-1][j-1].rgbtGreen;
            B = image[i-1][j].rgbtGreen;
            C = image[i-1][j+1].rgbtGreen;
            D = image[i][j-1].rgbtGreen;
            E = image[i][j].rgbtGreen;
            F = image[i][j+1].rgbtGreen;
            G = image[i+1][j-1].rgbtGreen;
            H = image[i+1][j].rgbtGreen;
            I = image[i+1][j+1].rgbtGreen;

            averageGreen = (A+B+C+D+E+F+G+H+I)/9;

            newImage[i][j].rgbtGreen = averageGreen;

            A = image[i-1][j-1].rgbtRed;
            B = image[i-1][j].rgbtRed;
            C = image[i-1][j+1].rgbtRed;
            D = image[i][j-1].rgbtRed;
            E = image[i][j].rgbtRed;
            F = image[i][j+1].rgbtRed;
            G = image[i+1][j-1].rgbtRed;
            H = image[i+1][j].rgbtRed;
            I = image[i+1][j+1].rgbtRed;

            averageRed = (A+B+C+D+E+F+G+H+I)/9;

            newImage[i][j].rgbtRed = averageRed;

        }
    } 
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = newImage[i][j];
        } 
    }
      
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
