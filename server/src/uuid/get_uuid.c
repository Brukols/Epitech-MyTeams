/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** get_uuid
*/

#include <uuid/uuid.h>
#include <stdlib.h>

char *get_uuid(uuid_t uuid)
{
    char *str = calloc(1, 37);

    if (!str)
        return (NULL);
    uuid_unparse(uuid, str);
    return (str);
}