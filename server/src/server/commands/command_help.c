/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** command_help
*/

#include "server.h"

static const char *response = "bonjour";

int command_help(server_t *server, client_t *client, client_request_t *req, char *data)
{
    server_reply_t header = {200, strlen(response)};
    bool ret;

    ret = smart_buffer_add_data(client->write_buf, &header, sizeof(server_reply_t));
    if (!ret)
        return (FAILURE);
    ret = smart_buffer_add_string(client->write_buf, response);
    if (!ret)
        return (FAILURE);
    return (SUCCESS);
}