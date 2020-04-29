/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** add_buffer
*/

#include <string.h>
#include <stdlib.h>

void *concat_buffer(void *dest, const void *src)
{
    char *tmp = dest ? strdup((char *)dest) : NULL;

    if (dest && !tmp)
        return (NULL);
    free(dest);
    dest = calloc(1, (tmp ? strlen(tmp) : 0) + strlen((char *)src) + 1);
    if (!dest)
        return (NULL);
    if (tmp)
        strcat((char *)dest, tmp);
    strcat((char *)dest, (char *)src);
    return (dest);
}