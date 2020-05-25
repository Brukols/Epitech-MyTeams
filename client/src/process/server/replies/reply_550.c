/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** TODO: add description
*/

#include "myteams_client.h"

int reply_550(client_t *info, server_reply_t *header)
{
    char message[header->message_size + 1];
    bzero(&message, header->message_size + 1);

    smart_buffer_get_data(info->server_out, &message, header->message_size);
    fprintf(stdout, "%s\n", message);
    return (CLIENT_SUCCESS);
}