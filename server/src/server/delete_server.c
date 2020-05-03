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
    free(server);
}
