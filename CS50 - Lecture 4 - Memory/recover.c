#include <stdint.h>
#include <stdio.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    char *input_file_name = argv[1];

    // Open input file
    FILE *input_file_content = fopen(input_file_name, "r");
    if (input_file_content == NULL)
    {
        printf("Could not open %s.\n", input_file_name);
        return 2;
    }

    FILE *output_file_content = NULL;

    BYTE buffer[BLOCK_SIZE];

    int output_file_counter = 0;

    char output_file_name[8];

    while (fread(buffer, 1, BLOCK_SIZE, input_file_content) == BLOCK_SIZE)
    {
        // Verify if it is the beginning of a new jpeg file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Verify if it is the first jpeg file
            if (output_file_counter != 0)
            {
                fclose(output_file_content);
            }

            sprintf(output_file_name, "%03i.jpg", output_file_counter);

            output_file_content = fopen(output_file_name, "w");

            if (output_file_content == NULL)
            {
                printf("Could not creat %s.\n", output_file_name);
                return 3;
            }

            fwrite(&buffer, 1, BLOCK_SIZE, output_file_content);

            output_file_counter++;
        }

        // Keep writing on an opened jpeg file
        else if (output_file_counter != 0)
        {
            fwrite(&buffer, 1, BLOCK_SIZE, output_file_content);
        }
    }

    fclose(output_file_content);
    fclose(input_file_content);
    return 0;
}