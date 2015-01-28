/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>

#include "dictionary.h"

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <ctype.h>

// node for linked list
typedef struct node {
    char word[LENGTH + 1];
    struct node* next;
} node;

// hashtable data structure
node* hashtable[HASHTABLE_SIZE] = { NULL };

// global variable for dictionary size
int dictionarySize = 0;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    char lower_case_word[LENGTH + 1];
    int len = strlen(word);
    
    for (int i = 0; i < len; i++)
        lower_case_word[i] = tolower(word[i]);
    
    lower_case_word[len] = '\0';
    
    int hash_result = hash_function(lower_case_word);
    
    if (hashtable[hash_result] == NULL)
        return false;
    
    node *traverse = hashtable[hash_result];
    
    while (traverse != NULL) {
        if (strcmp(lower_case_word, traverse -> word) == 0)
            return true;
        
        traverse = traverse -> next;
    }
    
    return false;        
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    FILE *file = fopen(dictionary, "r");
    
    if (file == NULL) {
        printf("Could not open %s.", dictionary);
        return false;
    }
    
    char dict_word[LENGTH + 1];
    
    while (fgets(dict_word, LENGTH + 1, file) != NULL) {
        // overwrite \n character with \0 terminator
        dict_word[strlen(dict_word) - 1] = '\0';
        
        // store result of hash function
        int hash_result = hash_function(dict_word);
        
        // allocate space for node
        node* newWord = malloc(sizeof(node));
        
        // copy dictionary word to node and set next to point to nothing
        strcpy(newWord -> word, dict_word);
        newWord -> next = NULL;
        
        if (hashtable[hash_result] == NULL) {
            // point to newly created node
            hashtable[hash_result] = newWord;
        } else {
            // append node at the end of the linked list
            node *traverse = hashtable[hash_result];
            
            while (traverse -> next != NULL)
                traverse = traverse -> next;
                
            traverse -> next = newWord;
        }
        
        dictionarySize++;
    }
    
    fclose(file);
    
    return true;    
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return dictionarySize;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    for (int i = 0; i < HASHTABLE_SIZE; i++) {
        node *traverse = hashtable[i];
        
        while (traverse != NULL) {
            node *temp = traverse -> next;
            free(traverse);
            traverse = temp;
        }
    }
    
    return true;
}

/**
 * Hash function to hash a word for the load operation
 */
int hash_function(char* word) {
    unsigned int hash = 0;
    
    for (int i = 0, n = strlen(word); i < n; i++)
        hash = (hash << 2) ^ word[i];
        
    return hash % HASHTABLE_SIZE;
}
