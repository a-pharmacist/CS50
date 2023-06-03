#include <cs50.h>
#include <stdio.h>

int get_start_population(void);
int get_end_population(int start_population);
int calculate_years_required(int start_population, int end_population);
void print_years(int years_required);

int main(void)
{
    // TODO: Prompt for start size
    int start_population = get_start_population();

    // TODO: Prompt for end size
    int end_population = get_end_population(start_population);

    // TODO: Calculate number of years until we reach threshold
    int years_required = calculate_years_required(start_population, end_population);

    // TODO: Print number of years
    print_years(years_required);
}


// TODO: Prompt for start size
int get_start_population(void)
{
    int start_population;
    do
    {
        start_population = get_int("Start population: ");
    }
    while (start_population < 9);
    return start_population;
}

// TODO: Prompt for end size
int get_end_population(int start_population)
{
    int end_population;
    do
    {
        end_population = get_int("End population: ");
    }
    while (end_population < start_population);
    return end_population;
}

// TODO: Calculate number of years until we reach threshold
int calculate_years_required(int start_population, int end_population)
{
    int years_required = 0;
    while (start_population < end_population)
    {
        start_population = start_population + start_population / 3 - start_population / 4;
        years_required ++;
    }
    return years_required;
}

// TODO: Print number of years
void print_years(int years)
{
    printf("Years: %i\n", years);
}

// STOP