// Implements a dictionary's functionality
#include <stdio.h>
#include <cs50.h>
#include <strings.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;
unsigned int word_count = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int h = hash(word);
    node *temp = table[h];
    while (temp != NULL)
    {
        if (strcasecmp(temp->word, word) == 0)
        {
            return true;

        }
        else
        {
            temp = temp->next;
        }


    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function

    // Function should take a string and return an index
    // This hash function adds the ASCII values of all characters in     the word together
    long sum = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        sum += tolower(word[i]);
    }
    return sum % N;

}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    //open dictionary file
    char word[LENGTH + 1];
    FILE *input = fopen(dictionary, "r");
    if (input == NULL)
    {
        return false;
    }

    //read file till the end

    while (fscanf(input, "%s", word) != EOF)
    {
        node *newnode = malloc(sizeof(node));
        if (newnode == NULL)
        {

            return false;
        }

        //copy every word to a new node
        strcpy(newnode->word, word);


        //hash the value for each node
        int h = hash(newnode->word);

        //insert node into the hashtable
        newnode->next = table[h];
        table[h] = newnode;
        word_count++;

    }
    fclose(input);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);

        }
        free(cursor);

    }

    return true;
}
