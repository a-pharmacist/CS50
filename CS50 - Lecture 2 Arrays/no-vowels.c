// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>

string replace(string array);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Incorrect number of command-line arguments\n");
        return 1;
    }
    else
    {
        printf("%s\n", replace(argv[1]));
    }
}

string replace(string array)
{
    for (int i = 0; array[i] != '\0'; i++)
    {
        switch (array[i])
        {
            case 'A':
            case 'a':
                array[i] = '6';
                break;

            case 'E':
            case 'e':
                array[i] = '3';
                break;

            case 'I':
            case 'i':
                array[i] = '1';
                break;

            case 'O':
            case 'o':
                array[i] = '0';
                break;
        }
    }
    return array;
}
