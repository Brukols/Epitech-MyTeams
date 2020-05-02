/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** send_bad_sequence_of_commands
*/

#include "server.h"

int send_bad_sequence_of_commands(client_t *client)
{
    server_reply_t header = {BAD_SEQUENCE, 0};

    if (!smart_buffer_add_data(client->write_buf, &header, sizeof(server_reply_t)))
        return (false);
    return (true);
}