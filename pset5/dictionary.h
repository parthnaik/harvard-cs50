/****************************************************************************
 * dictionary.h
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Declares a dictionary's functionality.
 ***************************************************************************/

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

// maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 46

// size of hash table
#define HASHTABLE_SIZE 65536

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word);

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary);

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void);

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void);

/**
 * Hash function to hash a word in dictionary for the load operation
 */
int hash_function(char* word);

#endif // DICTIONARY_H
