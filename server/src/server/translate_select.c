/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** translate_select
*/

#include "server.h"
#include "my_teams.h"
#include "client.h"
#include "user.h"

static int translate_select_client(server_t *server, list_t list, fd_set *readfs, \
fd_set *writefs)
{
    int ret;

    for (; list; list = list->next) {
        client_t *client = ((client_t *)list->value);

        if (FD_ISSET(client->fd, readfs))
            ret = read_data_client(server, client);
        if (ret < 0)
            return (FAILURE);
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
    for (list_t list = server->users; list; list = list->next) {
        user_t *user = ((user_t *)list->value);

        if (translate_select_client(server, user->client, readfs, writefs) < 0)
            return (FAILURE);
    }
    return (SUCCESS);
}