/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** delete_client
*/

#include "server.h"
#include <stdlib.h>
#include <unistd.h>

void delete_client(void *data)
{
    client_t *client = (client_t *)data;

    close(client->fd);
    free(client->write_buf);
    free(client->read_buf);
    if (client->path)
        free(client->path);
    free(data);
}