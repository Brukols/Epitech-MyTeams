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

    if (!smart_buffer_add_data(client->write_buf, &header, sizeof(header)))
        return (FAILURE);
    if (!smart_buffer_add_string(client->write_buf, message))
        return (FAILURE);
    return (SUCCESS);
}

int send_unknown(client_t *client, enum reply_code_e error, uuid_t uuid)
{
    server_reply_t header = {error, sizeof(uuid_t)};

    if (!smart_buffer_add_data(client->write_buf, &header, sizeof(header)))
        return (FAILURE);
    if (!smart_buffer_add_data(client->write_buf, uuid, sizeof(uuid_t)))
        return (FAILURE);
    return (SUCCESS);
}

int send_reply(client_t *client, enum reply_code_e error, const char *message)
{
    server_reply_t header = {error, message ? strlen(message) : 0};

    if (!smart_buffer_add_data(client->write_buf, &header, sizeof(header)))
        return (FAILURE);
    if (message)
        if (!smart_buffer_add_string(client->write_buf, message))
            return (FAILURE);
    return (SUCCESS);
}
