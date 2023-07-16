#include <stdlib.h>
#include <stdio.h>
#include <string.h> 
#include "source.h"

/**
 * \brief Creates a dynamically allocated array and reads the specified number of
 *        integers from the standard input stream.
 *
 * \param n The number of integers to be read
 * \return A pointer to the allocated and filled array
 */
int *create_dyn_array(unsigned int n)
{
    int *retval = (int *)malloc(n * sizeof(int));
    
    //if (retval == NULL) {
       // return NULL;
    //}
    
    for (unsigned int i = 0; i < n; i++) {
        scanf("%d", &retval[i]);
    }
    
    return retval;
}

/**
 * \brief Appends a new element to the existing and dynamically allocated array
 *
 * \param arr The dynamically allocated array of num elements
 * \param num The number of elements in arr
 * \param newval The value of the new element that will be appended
 * \return A pointer to the resized array
 */
int *add_dyn_array(int *arr, unsigned int num, int newval)
{
    int *retval = (int *)realloc(arr, (num + 1) * sizeof(int));
    
    /*if (retval == NULL) {
        return NULL;
    }*/
    
    retval[num] = newval;
    
    return retval;
}
