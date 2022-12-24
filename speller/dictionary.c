// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

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
    

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    if (islower(word[0]))
    {
        return word[0] - 'a';

    }
    else if (isupper(word[0]))
    {
        return word[0] - 'A';

    }
    return toupper(word[0]) - 'A';
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

    while (fcanf(input, %s, word) != EOF)
    {
        node *newnode = malloc(sizeof(node));
        if (newnode == NULL)
        {
            unload();
            return false;
        }

        //copy every word to a new node
        strcpy(newnode->word, word);
        newnode->next = NULL;

        //hash the value for each node
        int h = hash(newnode->word);

        //insert node into the hashtable
        node *head = table[h];
        if(head == NULL)
        {
            head = newnode;
            word_count++;
        }
        else
        {
            newnode->next = head;
            head = newnode;
            word_count++;
        }
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
    // TODO
    return false;
}