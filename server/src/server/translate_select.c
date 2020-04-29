/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** translate_select
*/

#include "server.h"
#include "my_teams.h"

int translate_select(server_t *server, fd_set *readfs, fd_set *writefs)
{
    if (FD_ISSET(server->fd, readfs)) {
        if (new_connection(server) < 0)
            return (FAILURE);
    }
    (void)writefs;
    return (SUCCESS);
}