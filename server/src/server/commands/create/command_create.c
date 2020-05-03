/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** command_create
*/

#include "server.h"

int command_create(server_t *server, client_t *client, client_request_t *req, \
char *data)
{
    if (client->thread)
        return (command_create_reply(server, client, req, data));
    if (client->channel)
        return (command_create_thread(server, client, req, data));
    if (client->team)
        return (command_create_channel(server, client, req, data));
    return (command_create_team(server, client, req, data));
}