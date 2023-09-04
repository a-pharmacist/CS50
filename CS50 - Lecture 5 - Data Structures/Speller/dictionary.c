// Implements a dictionary's functionality

#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 181;

unsigned int number_of_words;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    unsigned int index = hash(word);

    if (table[index]->next == NULL)
    {
        return false;
    }
    else
    {
        node *tmp = table[index]->next;
        do
        {
            int compare = strcasecmp(word, tmp->word);
            if (compare == 0)
            {
                return true;
            }
            tmp = tmp->next;
        }
        while (tmp != NULL);
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int index[] = {0, 0};

    index[0] = toupper(word[0]);
    index[1] = toupper(word[1]);

    return index[0] + index[1];
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    number_of_words = 0;

    FILE *input = fopen(dictionary, "r");
    if (input == NULL)
    {
        return false;
    }

    char buffer[LENGTH + 1];

    for (int i = 0; i < N; i++)
    {
        table[i] = malloc(sizeof(node));

        if (table[i] == NULL)
        {
            return false;
        }

        table[i]->next = NULL;
    }

    while (fscanf(input, "%s", buffer) != EOF)
    {
        unsigned int index = hash(buffer);
        node *new_word = malloc(sizeof(node));

        if (new_word == NULL)
        {
            return false;
        }

        strcpy(new_word->word, buffer);
        new_word->next = NULL;

        if (table[index]->next == NULL)
        {
            table[index]->next = new_word;
        }
        else
        {
            new_word->next = table[index]->next;
            table[index]->next = new_word;
        }

        number_of_words++;
    }

    fclose(input);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return number_of_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        if (table[i]->next == NULL)
        {
            free(table[i]);
        }
        else
        {
            node *tmp = table[i]->next;
            node *cursor = tmp->next;

            while (tmp != NULL)
            {
                free(tmp);
                tmp = cursor;

                if (cursor != NULL)
                {
                    cursor = cursor->next;
                }
            }

            free(table[i]);
        }
    }

    return true;
}
