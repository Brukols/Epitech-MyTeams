/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** translate_select
*/

#include "server.h"
#include "client.h"
#include "user.h"

static int translate_select_client(server_t *server, list_t list, \
fd_set *readfs, fd_set *writefs)
{
    int ret = 0;

    for (; list; list = list->next) {
        client_t *client = ((client_t *)list->value);

        if (FD_ISSET(client->fd, readfs))
            return (read_data_client(server, client));
        if (FD_ISSET(client->fd, writefs))
            ret = write_data_client(client);
        if (ret < 0)
            return (FAILURE);
    }
    return (SUCCESS);
}

int translate_select(server_t *server, fd_set *readfs, fd_set *writefs)
{
    if (FD_ISSET(server->fd, readfs)) {
        if (new_connection(server) < 0)
            return (FAILURE);
    }
    if (translate_select_client(server, server->client, readfs, writefs) < 0)
        return (FAILURE);
    return (SUCCESS);
}