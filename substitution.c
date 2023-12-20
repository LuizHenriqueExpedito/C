#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main (int argc, string argv[])
{
    //Check the number of arguments in the command line.
if (argc != 2)
{
    printf ("Use: ./Subistituition key\n");
    return 1;
}

// Loops through the length of the argument in the command line.
string key = argv[1];
for (int i = 0, n = strlen (key); i < n; i++)
{
    //Validates that the key consists only of letters.
    if (!isalpha (key [i]))
    {
        printf ("Use: ./Alphabetic key\n");
        return 1;
    }
}

//Validate if the key contains 26 characters.
    if (strlen (key)!= 26)
    return 1;
{
    printf ("Key needs contain 26 characteres\n");

}

//Checks if each alphabetic character is not repeated.
for (int i = 0, n = strlen(key); i < n; i++)
{
    for (int j = i + 1; j < n; j++)
    {
        if (toupper(key[i]) == toupper(key[j]))
        {
            printf ("Dont use repeat key alphabetic\n");
            return 1;
        }
    }
}

// Requests plain text from the user.
string plaintext = get_string ("Text: ");

//Converts all characters to uppercase.
for (int i = 0, n = strlen(key); i < n; i++)
{
    if (islower(key[i]))
    {
        key [i] -= 32;
    }
}

//Prints the encrypted text.
printf("ciphertext: ");
for (int i = 0, n = strlen (plaintext); i < n; i++)
{
    if (isupper(plaintext[i]))
    {
        int letter = plaintext[i] - 65;
        printf ("%c",key[letter]);
    }
    else if (islower (plaintext[i]))
    {
        int letter = plaintext[i] - 97;
        printf ("%c", key[letter] + 32);
    }
    else
    {
        printf ("%c", plaintext[i]);
    }
}
printf ("\n");
}
