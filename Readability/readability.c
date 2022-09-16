#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//Para compilar rode: gcc readability.c -o readability -lcs50 -lm
//Para executar rode: ./readability

//Implementação do Índice de Coleman–Liau (Nível de legibilidade de um texto.)

int main(void)
{
    int comprimento = 0;
    int space = 0;
    int countSpace = 0;
    int countPonto = 0;
    int countLower = 0;
    int countUpper = 0;
    int words = 0;
    int countFrase = 0;
    

    string texto = get_string("Digite o seu texto aqui: ");
  
        comprimento = strlen(texto);
        //printf("Seu texto tem  %d caracteres.\n", comprimento);

    // Abaixo está o cálculo do número de letras, espaços, frases e pontuação.
    // Como a string se comporta como um array, é preciso iterar cada posição do array. O "i" abaixo representa o índice do array.

        for (int i = 0; i < comprimento; i++){

            int letra = texto[i];

            if (islower(letra))
                countLower++;

            if (isupper(letra))
                countUpper++;

            if (isspace(letra))
                countSpace++;
        
            if (ispunct(letra))
                countPonto++;

            if (letra == 33 || letra == 46 || letra == 63)
                countFrase++;          
                    
            }

        words = countSpace + 1;

        //printf("Space: %i, Ponto: %i, Lower: %i, Upper: %i, Words: %i, Frase: %i\n", countSpace, countPonto, countLower, countUpper, words, countFrase);

    // Aqui calculamos as variáveis para a implementação da fórmula.

        float G = 0.0;
        float L = 0.0;
        float S = 0.0;

        G = words / 100.0;
        L = (countLower + countUpper) / G;
        S = countFrase / G;

        //printf("%.2f, %.2f, %.2f\n", G, L, S);

        // Abaixo temos a fórmula de Coleman-Liau.

        float index = 0.0;

        index = (0.0588 * L) - (0.296 * S) - 15.8;

        if (index < 1){
            printf("Before grade 1.\n");
            exit(0);
        }
            

        if (index > 16){
            printf("Grade 16+\n");
            exit(0);
        }

        printf("Grade %.0f\n", index);
   
}
   
