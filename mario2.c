#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n, i, j, k;

   do
    {
       n = get_int (" Pyramid Height: ");
    }

     while ( n < 1 || n > 8);

    for (i= 1; i <= n; i++) {

        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }

        for (j = 1; j <= i; j++) {


            printf("#");
  }

             printf(" ");

             for ( k = 1; k <= i; k++){

                printf("#");
             }


        printf("\n");
    }

    return 0;
}

