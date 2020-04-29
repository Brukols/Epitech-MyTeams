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
    dest = (char *)(calloc(1, strlen(dest) + strlen(src) + 1));
    if (!dest)
        return (NULL);
    strcat(dest, tmp);
    strcat(dest, src);
    return (dest);
}