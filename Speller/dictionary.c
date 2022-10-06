// Implements a dictionary's functionality

#include <stdbool.h>

#include "dictionary.h"
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

int words = 0;
void deleteList (node* ptrNode);
bool achou = false;

// Number of buckets in hash table
const unsigned int N = 300;

// Hash table (TODO)
node *table[N];

void find (node* ptrNode, const char* palavra)
{
    if (ptrNode == NULL || palavra == NULL)
    {
        achou = false;
    }
    else
    {
        if ((strcasecmp (ptrNode -> word, palavra)) == 0)
        {
            achou = true;
        }
        else
        {
            find (ptrNode -> next, palavra);
        }
    }
}


// Returns true if word is in dictionary, else false (TODO)
bool check(const char *wordText)
{

    int hashCode;

    hashCode = hash (wordText);

    find (table[hashCode], wordText);

    return achou;
    
}

// Hashes word to a number (TODO)

unsigned int hash(const char *word)
{
    int result = 0;

    if (word == NULL)
    {
        return 0;
    }

    while ((*word) != '\0')
    {
        result = result + (*word);
        word++;
    }
    result = result % N;
    return result;
}

// Loads dictionary into memory, returning true if successful, else false (TODO)
bool load(const char *dictionary)
{
    if (dictionary == NULL)
    {
        return false;
    }

    // Abrir o arquivo de dicionário
    FILE* fp;
    fp = fopen(dictionary, "r");

    // Ler palavra por palavra

    char palavra[LENGTH + 1];
    int status;
    int hashPosition;
    node* listNode;
    node* ptrNode;

    status = fscanf (fp, "%s", palavra);
    if (status == -1)
    {
        return false;
    }

    do
    { 
        // Calcular o hash de cada palavra
        hashPosition = hash (palavra);
     
        // Inserir a palavra na tabela conforme o hash

        listNode = malloc(sizeof(node));

    
        strcpy(listNode -> word, palavra);

    
        listNode -> next = table[hashPosition];
        table [hashPosition] = listNode;
        words ++;

    }
    while(fscanf (fp, "%s", palavra) != EOF);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return words;
}

// Unloads dictionary from memory, returning true if successful, else false (TODO)
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        if (table[i] == NULL)
        {
            continue;
        }
        else
        {
            deleteList (table[i]);
        }
    }
    
    return true;
}

void deleteList (node* ptrNode)
{
    if (ptrNode -> next == NULL)
    {
        free(ptrNode);
    }
    else
    {
        deleteList (ptrNode -> next);
    }
}
