#include <cs50.h>
#include <math.h>
#include <stdio.h>
//ESSE PROGRAMA MOSTRA QUANTAS MOEDAS PRECISO USAR PARA DEVOLVER O TROCO PARA UM CLIENTE USANDO OS DADOS DA ARRAY.
int main(void)
{
    float troco;
    int centavos, indice;
    int quantidade = 0;

    int moedas[] = {25, 10, 5, 1}; //Array armazena esses dados!
    do
    {
        troco = get_float("Troco devido: "); // Perrrgunta ao usuário.
    }
    while (troco <= 0);

    centavos = round(troco * 100);

    for (indice = 0; indice < 4; indice ++)
    {

        while (centavos - moedas[indice] >= 0 && centavos > 0)
        {
            centavos = centavos - moedas[indice];
            quantidade++;
        }
    }
    printf("%i\n", quantidade);
}

// Resivei o Arquivo 
