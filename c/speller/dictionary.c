// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <strings.h>
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
const unsigned int N = 600;

// Hash table
node *table[N];

//Size of the dictionary
int size_dictionary=0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int index=hash(word);
    node *ptr=table[index];

    while(ptr!=NULL)
    {
        if (strcasecmp(word,ptr->word)==0) return true;
        ptr=ptr->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int hash=0;
    for(int i=0,n=strlen(word);i<n;i++)
    {
        hash+=tolower(word[i]);
        hash=hash % N;
    }
    // TODO: Improve this hash function
    return hash;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *input=fopen(dictionary,"r");
    char buffer[LENGTH+1];
    int index;
    if(input==NULL)
    {
        return false;
    }
    while(fscanf(input,"%s", buffer)!=EOF)
    {
        node *n=malloc(sizeof(node));
        if(n==NULL)
        {
            return 1;
        }
        strcpy(n->word, buffer);
        index=hash(n->word);
        n->next=table[index];
        table[index]=n;
        size_dictionary++;
  }
  fclose(input);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if(size_dictionary!=0) return size_dictionary;
    else return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    node *ptr=NULL;
    for(int i=0; i <= N; i++)
    {
       ptr=table[i];
       while(ptr!=NULL)
        {
        node*next=ptr->next;
        free(ptr);
        ptr=next;
        }
    }
    if(ptr!=NULL) return false;
   else return true;
}
