/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** add_buffer
*/

#include <string.h>
#include <stdlib.h>

char *concat_buffer(char *dest, char *src)
{
    char *tmp = dest ? strdup(dest) : NULL;

    if (dest && !tmp)
        return (NULL);
    free(dest);
    dest = calloc(1, (tmp ? strlen(tmp) : 0) + strlen(src) + 1);
    if (!dest)
        return (NULL);
    if (tmp)
        strcat(dest, tmp);
    strcat(dest, src);
    return (dest);
}