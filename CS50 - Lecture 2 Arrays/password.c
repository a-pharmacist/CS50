// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    int c_verification[4];
    for (int i = 0; password[i] != '\0'; i++)
    {
        if (isdigit(password[i]) != 0)
        {
            c_verification[0] = 1;
        }
        else if (islower(password[i]) != 0)
        {
            c_verification[1] = 2;
        }
        else if (isupper(password[i]) != 0)
        {
            c_verification[2] = 3;
        }
        else if (isalnum(password[i]) == 0)
        {
            c_verification[3] = 4;
        }
    }
    if (c_verification[0] + c_verification[1] + c_verification[2] + c_verification[3] == 10)
    {
        return true;
    }
    return false;
}
