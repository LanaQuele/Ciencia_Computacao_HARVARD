#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


//Para compilar rode: gcc credit.c -o credit -lcs50 -lm
//Para executar rode: ./credit

int countDigit (long n);
int main (void)
{
   
    long number;
    int numberSize;
    int dig1, dig2, dig3, dig4, dig5, dig6, dig7, dig8;
    int soma1, soma2, soma3, soma4, soma5, soma6, soma7, soma8;
    int somaDig;
    int resto1, resto2, resto3, resto4, resto5, resto6, resto7, resto8;
    int somaResto;
    
    // Solicita o número do cartão de crédito e verifica se tem tamanho válido, entre 13 e 16.

    number = get_long("Enter your credit card number here: "); 
    numberSize = countDigit (number);

    if (numberSize < 13 || numberSize > 16)
    {
        printf ("INVALIDO - Condição 1\n");
        exit(0);
    }
    else{

    // Algorítimo de Luhn: Passo 1 - pega os dígitos do número do cartão, alternados, da direita para esquerda, começando do penúltimo, e multiplica cada um por 2.    

        dig1 = ((number % 100)/10*2);
        dig2 = ((number % 10000)/1000*2);
        dig3 = ((number % 1000000)/100000*2);
        dig4 = ((number % 100000000)/10000000*2);
        dig5 = ((number % 10000000000)/1000000000*2);
        dig6 = ((number % 1000000000000)/100000000000*2); 

        if (numberSize >= 14){
            dig7 = ((number % 100000000000000)/10000000000000*2);  
        }

        if (numberSize = 16){
            dig8 = ((number % 10000000000000000)/1000000000000000*2);  
        }
    // Imprime a sequência dos números multiplicados por 2, apenas para checar se está correto.

        //printf("%i, %i, %i, %i, %i, %i, %i, %i\n", dig1, dig2, dig3, dig4, dig5, dig6, dig7, dig8 );

    // Algorítimo de Luhn: Passo 2 - Pega cada dígito da sequência anterior e soma. Se for número de 2 dígitos separa e soma. Ex: 12 = 1 + 2. Abaixo, a separação dos dígitos.

        if (dig1 >= 10){
            soma1 = ((dig1 % 10)+ 1);
        }
        else {
            soma1 = dig1;
        }

        if (dig2 >= 10){
            soma2 = ((dig2 % 10)+ 1);
        }
        else {
            soma2 = dig2;
        }

        if (dig3 >= 10){
            soma3 = ((dig3 % 10)+ 1);
        }
        else {
            soma3 = dig3;
        }

        if (dig4 >= 10){
            soma4 = ((dig4 % 10)+ 1);
        }
        else {
            soma4 = dig4;
        }

        if (dig5 >= 10){
            soma5 = ((dig5 % 10)+ 1);
        }
        else {
            soma5 = dig5;
        }

        if (dig6 >= 10){
            soma6 = ((dig6 % 10)+ 1);
        }
        else {
            soma6 = dig6;
        }

        if (dig7 >= 10){
            soma7 = ((dig7 % 10)+ 1);
        }
        else {
            soma7 = dig7;
        }

        if (dig8 >= 10){
            soma8 = ((dig8 % 10)+ 1);
        }
        else {
            soma8 = dig8;
        }
        
    // Imprime a sequência dos dígitos separados, apenas para checar se está correto. 

        //printf("%i, %i, %i, %i, %i, %i, %i, %i\n", soma1, soma2, soma3, soma4, soma5, soma6, soma7, soma8);

    // Aqui, soma-se todos os dígitos.

        somaDig = (soma1 + soma2 + soma3 + soma4 + soma5 + soma6 + soma7 + soma8);
        
    // Imprime a soma dos dígitos, apenas para checar se está correto. 

        //printf("%i\n", somaDig);
    }

    // Algorítimo de Luhn: Passo 3 - pega os dígitos do número do cartão, alternados, da direita para esquerda, começando do último. Soma-os entre si + o resultado da soma do passo anterior. 

    resto1 = ((number % 10) / 1);
    resto2 = ((number % 1000) / 100);
    resto3 = ((number % 100000) / 10000);
    resto4 = ((number % 10000000) / 1000000);
    resto5 = ((number % 1000000000) / 100000000);
    resto6 = ((number % 100000000000) / 10000000000); 
    resto7 = ((number % 10000000000000) / 1000000000000);
    resto8 = ((number % 1000000000000000) / 100000000000000);

    // Imprime a sequência dos dígitos separados, apenas para checar se está correto. 

    //printf("%i, %i, %i, %i, %i, %i, %i, %i\n", resto1, resto2, resto3, resto4, resto5, resto6, resto7, resto8);

    // Aqui, efetua a soma do passo 3.

    somaResto = (resto1 + resto2 + resto3 + resto4 + resto5 + resto6 + resto7 + resto8 + somaDig);
    //printf("%i\n", somaResto);

    // Algorítimo de Luhn: Passo 4 - Para ser um número de cartão válido, a soma anterior tem que dar um número terminado em zero. Abaixo, o código faz essa checagem.

    int check = somaResto % 10;

    if(check !=0)
        {
        printf ("INVALIDO - Condição 2\n");
        exit(0);
    }

    // Aqui, verifica se o cartão é Visa.

    if (countDigit (number) == 16){
        bool visa16 = (number / 1000000000000000) == 4;

        if(visa16){
            printf("É Visa 16!\n");
            exit (0);
        }   
    }
    if (countDigit (number) == 13){
        bool visa13 = (number / 1000000000000) == 4;

        if(visa13){
            printf("É Visa 13!\n");
            exit (0);
        }   
    }
    
    // Aqui, verifica se o cartão é Amex.

    if (countDigit (number) == 15){
        bool amex34 = (number / 10000000000000) == 34;
        
        if (!amex34){
            bool amex37 = (number / 10000000000000) == 37;
            if (amex37){
                printf("É Amex 37!\n");
                exit (0);
            }
        }
        else{
            printf("É Amex 34!\n");
            exit (0);
        }
    }

    // Aqui, verifica se o cartão é Master.

    if (countDigit (number) == 16){
        bool master51 = (number / 100000000000000) == 51;
        
        if (!master51){
            bool master52 = (number / 100000000000000) == 52;
            if (master52){
                printf("É Master 52!\n");
                exit (0);

            }
            if (!master52){
                bool master53 = (number / 100000000000000) == 53;
                if (master53){
                    printf("É Master 53!\n");
                    exit (0);
                }
                if (!master53){
                    bool master54 = (number / 100000000000000) == 54;
                    if (master54){
                        printf("É Master 54!\n");
                        exit (0);
                    }
                    if (!master54){
                        bool master55 = (number / 100000000000000) == 55;
                        if (master55){
                            printf("É Master 55!\n");
                            exit (0);
                        }
                    }
                }

            }
        }
        else{
            printf("É Master 51!\n");
        }
    }
// Tem o número correto de dígitos, o número de checagem é correto, mas não atende as especificações de números iniciais que identificam cada cartão.

printf("INVALIDO - Condição 3\n");

}
// Essa função conta quantos dígitos tem o número do cartão de crédito. 
// Quando o loop passa por n = n /10, o valor de n está sendo atualizado.

int countDigit (long n)
    {
    int count = 0;  
    while (n != 0)
    {
        n = n / 10; 
        ++count;
    }
    return count;
    }


