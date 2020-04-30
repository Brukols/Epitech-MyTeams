/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** send_response
*/

#include "server.h"

int send_header_reply(unsigned short code, int size, client_t *client)
{
    server_reply_t header = {code, size};

    if (!smart_buffer_add_data(client->write_buf, &header, sizeof(server_reply_t)))
        return (FAILURE);
    return (SUCCESS);
}