#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "source.h"

/**
 * \brief Joins 3 arrays into a new dynamically allocated array
 *
 * \param n1 The number of elements in array a1
 * \param a1 The array 1 composed of n1 elements
 * \param n2 The number of elements in array a2
 * \param a2 The array 2 composed of n2 elements
 * \param n3 The number of elements in array a3
 * \param a3 The array 3 composed of n3 elements
 * \return a pointer to the dynamically allocated array
 *
 * \note The caller is responsible for deallocating the allocated array
 */
int *join_arrays(unsigned int n1,
                 const int *a1,
                 unsigned int n2,
                 const int *a2,
                 unsigned int n3,
                 const int *a3)
{

    int *result = (int*)malloc((n1 + n2 + n3) * sizeof(int));
    
    if (result == NULL) {
        // Memory allocation failed
        return NULL;
    }
    
    memcpy(result, a1, n1 * sizeof(int));
    
    // Copy elements from array a2 to the result array
    memcpy(result + n1, a2, n2 * sizeof(int));
    
    // Copy elements from array a3 to the result array
    memcpy(result + n1 + n2, a3, n3 * sizeof(int));
    
    return result;
}
