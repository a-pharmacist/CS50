#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(string message);

int main(void)
{
    string message = get_string("Message: ");
    print_bulb(message);
}

void print_bulb(string message)
{
    int l = strlen(message);
    int n[l];
    int r = 0;

    for (int i = 0; i < l; i++)
    {
        int bit[] = {0, 0, 0, 0, 0, 0, 0, 0};

        // Convert each char to int
        n[i] = message[i];
        int j = 0;

        do
        {
            r = n[i] % 2;
            n[i] = (float) n[i] / 2;

            // Verifies if the bulb must be on or off
            if (r == 1)
            {
                bit[BITS_IN_BYTE - j - 1] = 1;
            }
            j++;
        }
        while (n[i] > 0.5);

        for (int k = 0; k < BITS_IN_BYTE; k++)
        {
            if (bit[k] == 0)
            {
                // Dark emoji
                printf("\U000026AB");
            }
            else if (bit[k] == 1)
            {
                // Light emoji
                printf("\U0001F7E1");
            }
        }
        printf("\n");
    }
}