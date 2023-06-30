#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
void calculate_index(float number_of_letters, float number_of_words, float number_of_sentences);

int main(void)
{
    string text = get_string("Text: ");
    int number_of_letters = count_letters(text);
    int number_of_words = count_words(text);
    int number_of_sentences = count_sentences(text);
    calculate_index(number_of_letters, number_of_words, number_of_sentences);
}

int count_letters(string text)
{
    int i;
    int l;
    int text_lenght = strlen(text);
    for (i = 0, l = 0; i < text_lenght; i++)
    {
        if (isalpha(text[i]))
        {
            l++;
        }
    }
    return l;
}

int count_words(string text)
{
    int i;
    int l;
    int text_lenght = strlen(text);
    for (i = 0, l = 1; i < text_lenght; i++)
    {
        if (text[i] == ' ')
        {
            l++;
        }
    }
    return l;
}

int count_sentences(string text)
{
    int i;
    int l;
    int text_lenght = strlen(text);
    for (i = 0, l = 0; i < text_lenght; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            l++;
        }
    }
    return l;
}

void calculate_index(float number_of_letters, float number_of_words, float number_of_sentences)
{
    float L = number_of_letters / number_of_words * 100;
    float S = number_of_sentences / number_of_words * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}

