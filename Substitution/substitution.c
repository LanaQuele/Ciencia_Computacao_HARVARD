#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//Para compilar rode: gcc substitution.c -o substitution -lcs50 -lm
//Para executar rode: ./substitution

int main (int argc, string argv[])

{
    // argc é um argumento digitado na linha de comando. Ex: ./substitution hjeflsal, onde "hjeflsal" é o meu argumento, ou seja, a chave de criptografia. Portanto, argc contem duas posições sendo a primeira posição "./substitution" e a segunda "hjeflsal". Por isso, se o argc for diferente de 2 (ou seja, 2 posições) o programa pede a chave. Se for digitado, por exemplo: ./substitution hjsf okjd ohf, é considerado 4 posições.

    if (argc != 2)
    {
        printf("Usage: ./substitution Key\n");
        return 1;
    } 

    // Abaixo estamos verificando se todos os caracteres digitados são letras do alfabeto. Usamos duas funções já prontas: o strlen conta o comprimento do vetor e o isalpha verifica se o caracter da chave digitada contem apenas letras. Guardou a variável char1 para ser usada no pŕoximo "for".

    for (int i = 0; i < strlen (argv[1]); i++)
    {
        char char1 = argv[1][i];
        if (!isalpha(char1))
        {
            printf("A chave deve conter somente letras do alfabeto.\n");
            return 1; 
        }  

    // Abaixo temos um for dentro de outro for. Então, no for de cima, ele faz a primeira iteração e passa para esse for aqui. Aqui ele passa os caracteres para maiúsculo através da função toupper => faz isso para fazer a comparação a seguir, pois na tabela ascii, o maiúsculo e o minúsculo possui códigos diferentes. Então ele pega a variável char1 e compara com a variável char2, para ver se são iguais. Ele faz isso até iterar todos os índices. Ou seja, ele compara o i = 0 com o j = 0, o i = 0 com o j = 1, o i = 0 com o j = 2 e assim sucessivamente. Depois, volta no for de cima, onde agora o i = 1, volta nesse for aqui e faz tudo de novo. Até que i atinja o limite, ou seja, o tamanho do vetor (strlen). Isso para verificar se a chave contem caracteres repeditos.

        for (int j = 0; j < strlen (argv[1]); j++)
        {
            char char2 = argv[1][j];
            if (toupper(char1) == toupper(char2) && i != j)
            {
                printf("A chave não pode conter letras repetidas.\n");
                return 1;
            }
        }              
    }

    if (strlen(argv[1]) != 26)
        {
            printf("A chave deve conter 26 letras.\n");
            return 1; 
        }

    string textoSimples = get_string ("Texto simples: ");

    // Abaixo definimos que cada caracter do texto simples (texto digitado pelo usuário) se chamará letra. Então o "for" passa por cada letra do textoSimples, e verifica se é letra do alfabeto. Se não for, não faz nada, deixa inalterado. Se for letra, ele verifica se é minúscula. Se sim, pega o código ascii da letra e subtrai 97 (código ascii de "a"). O resultado é a posição do caracter a ser trocado na chave de criptografia digitada pelo usuario. Se for maiúsculo o procedimento é o mesmo, mas, subtrai 65 (código ascii de "A"). O "tolower" e o "toupper" serve para manter a maiúscula ou minúscula no textoSimples digitado pelo usuário.

    char letra;
    int posicaoLetra;

    for (int k = 0; k < strlen (textoSimples); k++)
    {
        letra = textoSimples[k];
        if (!isalpha (letra))
        {
            continue;
        }
        if (islower (letra))
        {
            posicaoLetra = letra - 97;          
            textoSimples[k] = tolower (argv[1][posicaoLetra]);
        }
        else
        {
            posicaoLetra = letra - 65;          
            textoSimples[k] = toupper (argv[1][posicaoLetra]);
        }

    }

        printf ("Texto criptografado: %s\n", textoSimples);

}