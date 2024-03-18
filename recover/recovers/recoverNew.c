#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;
 
int main(int argc, char *argv[])
{
 // We need two arguments.
 if (argc != 2)
 {
    printf("Usage: ./recover IMAGE\n");
    return 1;
 }
 // Open file.
  FILE *input_file = fopen (argv[1], "r");

  // Check if input is valid.
  if (input_file == NULL)
  {
    printf("Could not open the file");
    return 2;
  }
  // Size of array.
  unsigned char buffer [512];

  // How many images we found as valid one 
  int count_image = 0;

  // Pointer to recovered images.
  FILE *output_file = NULL;

  // Memory location.
  char *filename = malloc (8 * sizeof(char));

  // Read input_file 512 by 512
  while (fread(buffer, sizeof(char),512,input_file))
  {
    // Check patterns JPEG.
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer [3] & 0xf0) == 0xe0)
    {
        // Derermine name to file.JPEG
        sprintf (filename, "%03i.jpg",count_image);


        // Open out_put file to write in.
        output_file = fopen(filename, "w");

        // Count how many images we get it.
        count_image++;
    }
    if (output_file != NULL)
    {
        fwrite(buffer, sizeof(char),512,output_file);
    }
  }
free(filename);
fclose(output_file);
fclose(input_file);

return 0;

}