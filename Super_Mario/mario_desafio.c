#include <cs50.h>
#include <stdio.h>

//Para compilar rode: gcc mario_desafio.c -o mario_desafio -lcs50
//Para executar rode: ./mario_desafio

int main (void)
{
    int height, row, column, space;
    
    do
    { 
        height = get_int("Enter height here: ");
    }
    while (height < 1 || height > 8);

    for (row = 0; row < height; row++)
    {
        for (space = 0; space < height - row - 1; space++)
        {
            printf (" ");
        }
        for (column = 0; column <= row; column++)
        {
            printf ("#");
        }   
        printf ("  ");
        for (column = 0; column <= row; column++)
        {
            printf ("#");
        }

        printf ("\n");
                
    }
    
    
}