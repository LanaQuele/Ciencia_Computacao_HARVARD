#include <cs50.h>
#include <stdio.h>

//Para compilar rode: gcc hello.c -o hello -lcs50
//Para executar rode: ./hello

int main(void)
{
    string answer = get_string("Qual é o seu nome? ");
    printf("hello, %s\n", answer);
}