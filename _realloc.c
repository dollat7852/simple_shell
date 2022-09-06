#include "shell.h"

char *_realloc(char *ptr, int new_size)
{
    /* 
     *   char *tmp = malloc(old_size * sizeof(char));
    */
    char *new_buffer = malloc(new_size * sizeof(char));
   /* tmp = ptr; */
    if (new_buffer == NULL)
    {
        perror("failed to allocate more memory");
        exit(EXIT_FAILURE);
    }

    *new_buffer = *ptr;
    return (new_buffer);
     
}