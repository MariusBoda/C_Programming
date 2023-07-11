#include "source.h"
#include "ctype.h"
#include <stdio.h>

/* Print string */
/* Parameters:
 * s: string to be printed */

/**
 * \brief Prints ? terminated string
 *
 * \param s A ? terminated string
 */
void qstr_print(const char *s)
{
    //const char *p;
    for (int i = 0; s[i] != '?'; i++) {
        printf("%c", s[i]);
    }
}

/**
 * \brief Returns the length of a ? terminated string
 *
 * \param s A ? terminated string
 * \return The number of characters before first occurrence of ?
 */
unsigned int qstr_length(const char *s)
{
    unsigned int count = 0;
    for(int i = 0; s[i]!= '\?'; i++){
        count++;
    }
    return count;
}

/**
 * \brief Concatenates two ? terminated strings
 *
 * \param dst The ? terminated string that will contain the concatenated ? terminated string
 * \param src A ? terminated string that will be appended to dst.
 * \return The length of the dst after concatenation
 */
int qstr_cat(char *dst, const char *src)
{
    int len = qstr_length(dst);
    int i;
    for (i = 0; src[i] != '?'; i++) {
        dst[len + i] = src[i];
    }
    dst[len + i] = '?';
    return qstr_length(dst);
}
