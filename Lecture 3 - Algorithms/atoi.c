#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

long convert(string input);
long c = 0;

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%ld\n", convert(input));
}

long convert(string input)
{
    int n = strlen(input), s = 0, i = 0;

    // Stop recursion
    if (input[n - 1] == ' ')
    {
        return 0;
    }

    // Skip white spaces
    while (input[i] == ' ')
    {
        i++;
    }

    // Get the corresponding Algarism
    s = input[i] - '0';

    // Move one index right on the forward execution.
    input[i] = ' ';

    c = c * 10 + s;

    convert(input);

    return c;
}