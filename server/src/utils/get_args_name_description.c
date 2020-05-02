/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** get_args_name_description
*/

#include "server.h"

int get_args_name_description(char *name, char *description, \
client_request_t *req, char *data)
{
    int size_name = strnlen(data, req->message_size);
    int size_description;

    if (size_name == 0 || size_name >= DEFAULT_NAME_LENGTH)
        return (FAILURE);
    strncpy(name, data, size_name);
    size_description = strnlen(data + size_name + 1, req->message_size);
    if (size_description >= DEFAULT_DESCRIPTION_LENGTH)
        return (FAILURE);
    strncpy(description, data + size_name + 1, size_description);
    return (SUCCESS);
}