#include "source.h"
#include "ctype.h"

/**
 * \brief Counts alphabetical characters in a string
 *
 * \param str The string to be processed
 * \return The number of alphabetical characters
 */
int count_isalpha(const char *str)
{
    int count = 0;
    for(int i = 0; str[i]!= '\0'; i++){
        if(isalpha(str[i])) count++;
    }
    return count;
}
