#include <cs50.h>
#include <stdio.h>


//Para compilar rode: gcc population.c -o population -lcs50 -lm
//Para executar rode: ./population

int main (void)
{
    int startSize, endSize, born, die, growYear, ciclo;
    ciclo = 0;

    // Solicita o tamanho da população inicial.

    do
        { 
        startSize = get_int("Enter with the initial population here: ");       
    }
    while (startSize < 9);

    // Solicita o tamanho da população final.

    do
        { 
        endSize = get_int("Enter with the end population here: ");
    }
    while (endSize <= startSize);

    // Calcula quantos nascimentos e quantas mortes por ano. Pega esse resultado e usa para o próximo cálculo, até que o growYear seja maior que o endSize.

    // O ciclo++ representa quantas vezes o processo abaixo foi repetido. E isso indica então quantos anos é necessário para atingir a população final.

    do{
        born = startSize / 3;
        die = startSize / 4;
        growYear = startSize + born - die;
        ciclo++;

        startSize = growYear;
    }
    while (endSize > growYear);
   
    printf ("Total de anos: %i\n", ciclo);

    // Imprimindo os dados apenas para verificação:

    //printf ("%i, %i, %i, %i\n", born, die, growYear, ciclo);
   
}

