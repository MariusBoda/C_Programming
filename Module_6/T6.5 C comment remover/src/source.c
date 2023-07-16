
#include "source.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * \brief Removes the C comments from the input C code.
 *
 * \details The function polishes the code by */
//          - removing the block comments delimited by /* and */.
/*            These comments may span multiple lines.You should remove only */
//            characters starting with /* and ending with */. The characters,
/*            including white space characters (' ', \n, \r, \t), */
//            after */ should not be removed.
/*
 *          - remove the line comments starting with // until and including the
 *            newline character \n.
 *
 * \param input A code segment that contains some comments.It is a dynamically
 *              allocated string(array of characters).
 * \return A pointer to the polished code
 */

char *delete_comments(char *input)
{
    size_t input_len = strlen(input);
    char *retval = malloc(input_len + 1);
    char *dest = retval;
    char *src = input;
    int in_block_comment = 0;
    int in_line_comment = 0;

    while (*src != 0)
    {
       
        if (!in_block_comment && !in_line_comment && *src == '/' && *(src + 1) == '*')
        {
            in_block_comment = 1;
            src += 2; 
        }
    
        else if (!in_block_comment && !in_line_comment && *src == '/' && *(src + 1) == '/')
        {
            in_line_comment = 1;
            src += 2; 
        }
        else if (in_block_comment && *src == '*' && *(src + 1) == '/')
        {
            in_block_comment = 0;
            src += 2; 
        }
        else if (in_line_comment && *src == '\n')
        {
            in_line_comment = 0;
            src++; 
        }
        else if (!in_block_comment && !in_line_comment)
        {
            *dest++ = *src++;
        }
        else
        {
            src++; 
        }
    }

    *dest = 0;

    if (input != retval)
    {
        free(input); 
    }

    return retval;
}

