// Practice working with structs
// Practice applying sorting algorithms

#include <cs50.h>
#include <stdio.h>

#define NUM_CITIES 10

typedef struct
{
    string city;
    int temp;
}

avg_temp;

avg_temp temps[NUM_CITIES];

void sort_cities(void);

int main(void)
{
    temps[0].city = "Austin";
    temps[0].temp = 97;

    temps[1].city = "Boston";
    temps[1].temp = 82;

    temps[2].city = "Chicago";
    temps[2].temp = 85;

    temps[3].city = "Denver";
    temps[3].temp = 90;

    temps[4].city = "Las Vegas";
    temps[4].temp = 105;

    temps[5].city = "Los Angeles";
    temps[5].temp = 82;

    temps[6].city = "Miami";
    temps[6].temp = 97;

    temps[7].city = "New York";
    temps[7].temp = 85;

    temps[8].city = "Phoenix";
    temps[8].temp = 107;

    temps[9].city = "San Francisco";
    temps[9].temp = 66;

    sort_cities();

    printf("\nAverage July Temperatures by City\n\n");

    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf("%s: %i\n", temps[i].city, temps[i].temp);
    }
}

// Sort cities by temperature in descending order
void sort_cities(void)
{
    int i = 0, j = 0, k = 0;

    do
    {
        if (temps[i].temp < temps[i + 1].temp)
        {
            j = 0;

            // Uses an object for switching the array's elements' position.
            avg_temp object;
            object = temps[i];

            temps[i] = temps[i + 1];
            temps[i + 1] = object;

            // Checks if it is the end of the array.
            if (i == NUM_CITIES - 2)
            {
                // Prepares the while loop for one more execution, starting from the beginning (i.e., index 0).
                i = 0;
            }
            else
            {
                i++;
            }
        }
        else
        {
            // Counts the number of times during an execution that no moves were made.
            j++;

            if (i == NUM_CITIES - 2)
            {
                // Prepares the while loop for one more execution, starting from the beginning (i.e., index 0).
                i = 0;

                // Checks if no moves were made during an entire execution. k = 1 is the sign for breaking.
                if (j == NUM_CITIES - 1)
                {
                    k = 1;
                }

                j = 0;
            }
            else
            {
                i++;
            }
        }
    }
    while (k == 0);
}