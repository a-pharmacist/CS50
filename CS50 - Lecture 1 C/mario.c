#include <cs50.h>
#include <stdio.h>

int get_height(void);
void print_pyramids(int height);

int main(void)
{
    //TODO: ask the user how tall the pyramids should be.
    int height = get_height();
    //TODO: calculate the pyramids' height, number of hashes required on each line, and print the result on the screen.
    print_pyramids(height);
}

int get_height(void)
{
    int height;
    do
    {
        height = get_int("Pyramids' height: ");
    }
    while (height < 1 || height > 8);
    return height;
}

void print_pyramids(int height)
{
    // Defines pyramids' height.
    for (int i = 0; i < height; i++)
    {
        // Defines the number of spaces.
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }

        // Defines the number of hashes.
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }

        // Creates spaces between pyramids.
        printf("  ");

        // Creates another half-pyramid.
        
        for (int l = 0; l <= i; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}
