#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
//give one command line argument
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

//read file
    FILE *input_file = fopen(argv[1], "r");

//check that file is  valid
    if (input_file == NULL)
    {
        printf("can't open file");
        return 2;

    }
// store blocks into araays
    unsigned char buffer[512];

//images generated
    int count_image = 0;

//file pointer for images
    FILE *output_file = NULL;
//file name
    char *filename = malloc(8 * sizeof(char));

//read blocks
    while (fread(buffer, sizeof(char), 512, input_file))
    {
        //check start of JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // write file
            sprintf(filename, "%03i.jpg", count_image);

            //open output file for writing
            output_file = fopen(filename, "w");

            count_image++;
        }
        //check output validity
        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output_file);
        }
    }
    free(filename);
    fclose(output_file);
    fclose(input_file);
    return 0;

}