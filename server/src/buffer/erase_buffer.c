/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** erase_buffer
*/

#include <string.h>
#include <stdlib.h>

char *erase_buffer(char *buffer, long pos)
{
    char *new_buffer = malloc(strlen(buffer) - pos + 1);
    int a = 0;

    if (!new_buffer)
        return (NULL);
    for (long i = pos; buffer[i]; i++, a++) {
        new_buffer[a] = buffer[i];
    }
    new_buffer[a] = 0;
    free(buffer);
    return (new_buffer);
}