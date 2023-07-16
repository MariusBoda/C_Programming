#include "source.h"

#include <stdlib.h>
#include <string.h>

char *my_strcat(char *dest, const char *src)
{
    size_t dest_len = strlen(dest);
    size_t src_len = strlen(src);
    
    char *newdest = realloc(dest, dest_len + src_len + 1);  
    
    dest = newdest;
    dest += dest_len;

    while (*src)
    {
        *dest++ = *src++; 
    }
    *dest = 0; 

    return dest;
}
