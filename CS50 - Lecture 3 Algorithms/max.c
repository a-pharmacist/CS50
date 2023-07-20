// Practice writing a function to find a max value

#include <cs50.h>
#include <stdio.h>

int max(int array[], int n);

int main(void)
{
    // Gets the number of elements of the array
    int n;
    do
    {
        n = get_int("Number of elements: ");
    }
    while (n < 1);

    // Declares the array of integers
    int arr[n];

    // Gets the elements of the array
    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i);
    }

    printf("The max value is %i.\n", max(arr, n));
}

// TODO: return the max value
int max(int array[], int n)
{
    int max;

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (array[i] > array[i + 1])
            {
                max = array[i];
            }
            else
            {
                max = array[i + 1];
            }
        }
        else
        {
            if (max < array[i])
            {
                max = array[i];
            }
        }
    }
    return max;
}