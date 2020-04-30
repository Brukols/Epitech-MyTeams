/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** command_logout
*/

#include "server.h"

const char *response = "Goodbye";

int command_logout(server_t *server, client_t *client, client_request_t *req, char *data)
{
    client->close = true;
    send_header_reply(200, strlen(response), client);
    if (!smart_buffer_add_string(client->write_buf, response))
        return (FAILURE);
    (void)server;
    (void)req;
    (void)data;
    return (SUCCESS);
}