#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Initial size of the population.
    int i;
    do 
    {
        i = get_int ("Start population: \n");
    }
    while ( i < 9);

    // Desired final population size.
    int j;
    do
    {
        j = get_int ("End population: \n");
    }
    while (j < i);

    // Calculate the number of years until the population increases from the initial population to the desired one.
    int years = 0;
    while (i < j)
    {
        i = i + ( i / 3) - ( i / 4);
        years++;
    }
    // Print number of years
    printf(" Years: %d\n", years);


    
}