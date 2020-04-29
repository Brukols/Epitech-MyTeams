/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** create_client
*/

#include "server.h"
#include <string.h>
#include <stdlib.h>

client_t *create_client(int fd)
{
    client_t *client = malloc(sizeof(client_t));

    if (!client)
        return (NULL);
    client->fd = fd;
    client->close = false;
    client->write_buf = strdup("");
    client->read_buf = strdup("");
    client->path = NULL;
    return (client);
}