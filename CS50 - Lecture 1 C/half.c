// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

float half(float bill_amount, float tax_percent, int tip_percent);

int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_int("Tip percent: ");

    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));
}

// TODO: Complete the function
float half(float bill_amount, float tax_percent, int tip_percent)
{
    // Changing the data type is necessary. Otherwise, the function will ignore the numbers after the dot.
    float float_tip_percent = tip_percent;
    float tax_added = ((bill_amount * (1 + tax_percent / 100)) * (1 + float_tip_percent / 100)) / 2;
    return tax_added;
}
