#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

//Para compilar rode: gcc scrabble.c -o scrabble -lcs50 -lm
//Para executar rode: ./scrabble

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }

    if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }

    if (score1 == score2)
    {
        printf("Tie!\n");
    }

}
int compute_score(string word)
{
    char letra;
    int posicaoPoints;
    int soma = 0;

    for (int i = 0; i < strlen (word); i++)
    {
        letra = word[i];
        if (!isalpha (letra))
        {
            continue;
        }
        if (islower (letra))
        {
            posicaoPoints = letra - 97;          
            soma = POINTS[posicaoPoints] + soma;
        }
        else 
        {
            posicaoPoints = letra - 65;          
            soma = POINTS[posicaoPoints] + soma;
        }

    }
    
    return soma;
}