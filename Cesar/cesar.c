#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//Para compilar rode: gcc cesar.c -o cesar -lcs50 -lm
//Para executar rode: ./cesar

int main (int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./cesar Key\n");
        return 1;
    }

    for (int i = 0; i < strlen (argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./cesar Key\n");
            return 1; 
        } 
    }
        int k = atoi(argv[1]);

        string textoSimples = get_string ("Texto simples: ");
        printf ("Texto criptografado: ");

        for (int j = 0; j < strlen (textoSimples); j++)
        {
            if(isupper(textoSimples[j]))
            {
                printf ("%c", (textoSimples[j] - 65 + k) %26 + 65);
            }

            else if (islower(textoSimples[j]))
            {
                printf ("%c", (textoSimples[j] - 97 + k) %26 + 97);
            }

            else 
            {
                printf ("%c", textoSimples[j]);
            }
            
        }

        printf ("\n");
    
} 