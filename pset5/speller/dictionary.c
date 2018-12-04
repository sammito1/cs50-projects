// Implements a dictionary's functionality

#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>

#include "dictionary.h"

// declare hash table as a global variable, with 26 'buckets' for each letter of the alphabet
node *hashtable[26];

// declare global variable "counter", this will be used in the size() function.
unsigned int counter = 0;

// initialize hash() function to be used by load()
int hash(char word[]);

// initialize destroy() function to be used by unload()
void destroy(node *head);

// Returns true if word is in dictionary else false

bool check(const char *word)
{
    char first_letter = word[0];

    // declare int bucket, corresponding to the respective llist containing the given word
    int bucket;

    if (!isalpha(first_letter))
    {
        return false;
    }
    if (isupper(first_letter))
    {
        // TODO for uppercase
        bucket = first_letter - 65;
    }
    else
    {
        // TODO for lowercase
        bucket = first_letter - 97;
    }

    node *trav = hashtable[bucket];

    // if there are no nodes in the bucket, return false
    if (trav == NULL)
    {
        return false;
    }

    // if there are nodes in the bucket, search through them
    while (trav != NULL)
    {
        if (strcasecmp(trav->word, word) == 0)
        {
            return true;
        }
        trav = trav->next;
    }

    // if the word is not found (i.e it makes it out of the previous loop), return false
    return false;
}



// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    /* this code was said to be unecessary by a staff member
    // set all pointers to NULL in hash table
    for (int i = 0; i < 26; i++)
    {
        hashtable[i] = NULL;
    }
    */

    // open dictionary file
    FILE *file = fopen(dictionary, "r");

    if (file == NULL)
    {
        return false;
    }

    // initialize a new node
    node *new_node = NULL;

    // initialize buffer char array
    char word[LENGTH + 1];

    // until you reach EOF of the dictionary file, scan each string into the variable "word"
    while (fscanf(file, "%s", word) != EOF)
    {
        // initialize a new node
        // remember, new_node is a pointer-to-node, as malloc returns an ADDRESS.
        new_node = malloc(sizeof(node));

        // if there is no space for new node, unload dictionary from memory and return false.
        if (new_node == NULL)
        {
            unload();
            fclose(file);
            return false;
        }

        // set word field in new_node as local variable "word"
        // we use strcpy because of C's limitations in regard to strings.
        strcpy(new_node->word, word);

        new_node->next = NULL;

        // hash the word in order to find the respective bucket in hash table
        int bucket = hash(word);

        // insert new node into respective linked list

        // if the respective bucket has a ptr to NULL, create a new linked list by setting the ptr to the new node.
        // the new node's `next` field will still be set to NULL.
        if (hashtable[bucket] == NULL)
        {
            hashtable[bucket] = new_node;
            counter++;
        }
        // otherwise, there is a ptr to the head of a linked list already in it, so insert into the head of the list.
        else
        {
            new_node->next = hashtable[bucket];
            hashtable[bucket] = new_node;
            counter++;
        }
    }
    // program will reach this point as long as there was enough memory to store the words.

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return counter;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // if nothing was loaded in the first place.. simply return false
    if (counter == 0)
    {
        return false;
    }
    // for each bucket in hash table..
    for (int i = 0; i < 26; i++)
    {
        // if bucket contains a null pointer, skip to next bucket
        if (hashtable[i] == NULL)
        {
            continue;
        }
        // otherwise, if bucket has a pointer to the head of a linked list
        else
        {
            destroy(hashtable[i]);
        }
    }

    // function will get to this point if successfully unloaded (hopefully).
    return true;
}


/*
This is a simple hash function that assigns each dictionary word into a bucket, based on its first letter/character.
There are 26 letters in the alphabet, hence the hash table with 27 buckets, one for each letter.
It returns an int value, corresponding to the word's respective hash bucket.
*/

int hash(char word[])
{

    char firstletter = word[0];
    int bucket;

    if (islower(firstletter))
    {
        bucket = firstletter - 97;
    }
    else
    {
        bucket = firstletter - 65;
    }

    return bucket;
}

// this destroy function free()'s all the nodes in a linked list.
void destroy(node *head)
{
    if (head == NULL)
    {
        return;
    }
    if (head->next != NULL)
    {
        destroy(head->next);
    }
    free(head);
}

