/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** send_error_arguments
*/

#include "server.h"

int send_error_arguments(client_t *client, const char *message)
{
    server_reply_t header = {SYNTAX_ERROR_ARGS, strlen(message)};

    if (!smart_buffer_add_data(client->write_buf, &header, sizeof(server_reply_t)))
        return (FAILURE);
    if (!smart_buffer_add_string(client->write_buf, message))
        return (FAILURE);
    return (SUCCESS);
}