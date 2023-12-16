#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main (void)
{
    // Ask the user for a text:
    string text = get_string("text: ");
    
    // Count the number of letters in the text.
    int letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++) // calculate string length.
    {
        if ( isalpha(text [i])) // Check if the character is a alphabetical.
        {
            letters++;
        }
    } 

// Count the number of words.
int words = 1;
for (int i = 0, n = strlen(text);i < n ; i++)
{
    if (isspace(text[i])) // Check if a character is a whithespace.
{
    words++;
}

}

// Count the number of sentences.
int sentences = 0;
for (int i = 0, n = strlen(text); i < n; i++)
{
    if (text[i] == '.' || text[i] == '!' || text[i] == '?')
    {
        sentences++;
    }
}

// Use Coleman-Liau's index to determine the reading level.
float calculation = (0.0588 * letters / words * 100 ) - 
                    (0.296 * sentences/ words * 100) -
                    15.8;
int index = round (calculation);

// Check the reading level.
if (index < 1 )
{
    printf ("Before Grade 1\n");
    return 0;
}
else if (index >= 16)
{
    printf ("Grade 16+\n");
    return 0;
}
else
  {
    printf ("Grade %i\n", index);
  }
}