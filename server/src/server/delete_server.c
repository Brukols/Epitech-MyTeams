/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** delete_server
*/

#include "server.h"
#include <unistd.h>

void delete_server(server_t *server)
{
    close(server->fd);
    if (server->client)
        list_clear(&server->client, &delete_client);
    if (server->users)
        list_clear(&server->users, &delete_user);
    if (server->teams)
        list_clear(&server->teams, &delete_team);
    free(server);
}
