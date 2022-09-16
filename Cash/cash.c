#include <cs50.h>
#include <stdio.h>
#include <math.h>


//Para compilar rode: gcc cash.c -o cash -lcs50 -lm
//Para executar rode: ./cash

int main (void)
{
    float change; 
    long cents;

    do
        { 
        change = get_float("Enter your change here: ");
    }
    while (change <= 0);

    cents = round(change*100);
    long coins25 = 0;
    long coins10 = 0;
    long coins5 = 0;
    long coins1 = 0;

coins25 = cents/25;
long rest25 = cents%25;

coins10 = rest25/10;
long rest10 = rest25%10;

coins5 = rest10/5;
long rest5 = rest10%5;

coins1 = rest5/1;
long rest1 = rest5%1;


/*
    while (cents >= 25)
    {
        cents -=25;
        coins25++;
    }

    while (cents >= 10)
    {
        cents -=10;
        coins10++;
    }

    while (cents >= 5)
    {
        cents -=5;
        coins5++;
    }

    while (cents >= 1)
    {
        cents -=1;
        coins1++;
    }*/

    printf ("You will need at least %li coins of 25\n", coins25);
    printf ("You will need at least %li coins of 10\n", coins10);
    printf ("You will need at least %li coins of 5\n", coins5);
    printf ("You will need at least %li coins of 1\n", coins1);
}
