/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** send_error_already_exist
*/

#include "server.h"

int send_error_already_exist(client_t *client)
{
    server_reply_t header = {CLIENT_ALREADY_EXISTS, 0};

    if (!smart_buffer_add_data(client->write_buf, &header, sizeof(server_reply_t)))
        return (false);
    return (true);
}