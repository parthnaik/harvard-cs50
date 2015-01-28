/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

// Declarations
// Linear Search
bool linear(int value, int array[], int n);

// Binary Search
bool binary(int value, int array[], int n);


/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // Return false if n is not positive.
    if (value < 0)
        return false;
        
    // Binary Search
    return binary(value, values, n);
}

// Linear Search
bool linear(int value, int array[], int n) {
    for (int i = 0; i < n; i++)
        if (array[i] == value)
            return true;
    
    return false;
}

// Binary Search
bool binary(int value, int array[], int n) {
    int imin = 0, imax = n - 1;
    int imid;
    
    while (imax >= imin) {
        imid = (imin + imax) / 2;
        
        if (array[imid] == value)
            return true;
        else if (array[imid] < value)
            imin = imid + 1;
        else
            imax = imid - 1;    
    }
    
    return false;
}

/**
 * Sorts array of n values.
 */
// Bubble Sort
void sort(int values[], int n)
{
    void swap(int array[], int index1, int index2);
    bool swapped;
    
    do {
        swapped = false;
    
        for (int i = 1; i < n; i++) {
            if (values[i] < values[i - 1]) {
                swap(values, i, i - 1);
                swapped = true;
            }
        }
        
        n = n - 1;   
        
    } while (swapped == true);
}

void swap(int array[], int index1, int index2) {
    int temp = array[index2];
    array[index2] = array[index1];
    array[index1] = temp;
}
