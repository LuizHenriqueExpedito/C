#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
// This program encrypts a text using the Caesar cipher... Where the user informs which number will be used as the key!
int main (int argc, string argv[]) 
{
    // Checks the numbers of arguments in the command line.
    if (argc !=2)
    { 
        printf ("Use: ./caesar key\n"); 
        return 1;    
    }
    // Checks the extention of the arguments in the command line.
    for (int i = 0, n = strlen(argv[1]); i < n ; i++)
    {
        if (!isdigit (argv[1][i]))
        {
            printf("Use: ./ caesar key\n");
            return 1;
        }
    }
// Converts string to integer.
int k = atoi(argv[1]);
// Ask for a text from the user.
string plaintext = get_string ("Text: ");
printf ("Ciphertext: ");

// Calculation for resolution.
for (int i = 0, n = strlen (plaintext); i < n; i++)
{
    if (isupper (plaintext[i]))
    {
        printf ("%c",(plaintext[i] - 65 + k  ) % 26 + 65);
    }
    else if (islower (plaintext [i]))
    {
        printf ("%c", (plaintext [i] - 97 + k) % 26 + 97);
    }
    else
     {
        printf ("%c",plaintext [i]);
     }
    }
    
    printf("\n");

}
