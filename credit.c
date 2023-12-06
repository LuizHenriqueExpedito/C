#include <cs50.h>
#include <math.h>
#include <stdio.h>

int num_digitos (long num_cartao);
int dois_primeiros (long num_cartao, int numeros_de_digitos);
int multiplicar (long num_cartao);
int somar (long num_cartao);
int valido (int resultado_algoritmo,int dois_primeiros_digitos, int numeros_de_digitos);

int main (void)
{
long num_cartao = get_long ("Número: ");
int numeros_de_digitos = num_digitos (num_cartao);
int dois_primeiros_digitos = dois_primeiros (num_cartao,numeros_de_digitos);
int multiplicacao = multiplicar (num_cartao);
int soma = somar (num_cartao);

int resultado_algoritmo = multiplicacao + soma;

valido (resultado_algoritmo, dois_primeiros_digitos, numeros_de_digitos);
}

// FUNÇÕES
int num_digitos (long num_cartao)
{
int num_digitos = 0;
while (num_cartao > 0)
{
    num_cartao /= 10 ;
    num_digitos ++;
}
return num_digitos;
}

int dois_primeiros (long num_cartao, int numeros_de_digitos)
{
    int dois_primeiro = num_cartao/pow (10, numeros_de_digitos -2);

return dois_primeiro;
}

int multiplicar (long num_cartao)
{
    int multiplicacao = 0;
    int operacao;
    while (num_cartao > 0)
    {
        num_cartao /= 10;
operacao = (num_cartao % 10) * 2;
if (operacao > 9)
{
    operacao = (operacao % 10 ) + (operacao / 10);
}
multiplicacao = operacao + multiplicacao;
num_cartao /= 10;
}
return multiplicacao;
}
int somar (long num_cartao)
{
    int soma = 0;
    while (num_cartao > 0)
    {
        soma = (num_cartao %10) + soma;
        num_cartao /= 100;
    }
    return soma;
}

int valido (int resultado_algoritmo, int dois_primeiros_digitos,int numeros_de_digitos)
{
    if (resultado_algoritmo %10 == 0)
    {
        if ((dois_primeiros_digitos == 34 || dois_primeiros_digitos ==37 ) && (numeros_de_digitos ==15))
        {
            return printf ("AMEX\n");
        }
        else if ((dois_primeiros_digitos >= 51 && dois_primeiros_digitos <= 55) &&(numeros_de_digitos == 16 ))
        {
            return printf("MASTERCARD\n");
        }
        else if ((dois_primeiros_digitos >= 40 && dois_primeiros_digitos <= 49) &&
        (numeros_de_digitos <= 16 && numeros_de_digitos >= 13))
        {
            return printf("VISA\n");
        }
        else
        {
            return printf ("INVALID\n");
        }
    }
    else
    {
        return printf("INVALID\n");
  }
}









