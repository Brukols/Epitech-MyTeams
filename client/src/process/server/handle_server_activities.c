/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** TODO: add description
*/

#include "myteams_reply.h"

static bool if_good_reply(smart_buffer_t *buffer, void *data)
{
    server_reply_t *reply = data;

    if (smart_buffer_get_size(buffer) >= reply->message_size + sizeof(server_reply_t))
        return (true);
    return (false);
}

static int handle_server_reply(client_t *info, server_reply_t header)
{
    int ret = CLIENT_ERROR;

    for (int i = 0; replies[i].code; i++) {
        if (header.reply == replies[i].code) {
            ret = replies[i].ft(info, &header);
            break;
        }
    }
    if (ret == CLIENT_ERROR)
        fprintf(stdout, "Invalid response from server : %hu\n", header.reply);
    return (CLIENT_SUCCESS);
}

int handle_server_activities(client_t *info)
{
    server_reply_t header = {0};

    while (smart_buffer_get_data_if(info->server_out, &header, sizeof(server_reply_t), &if_good_reply)) {
        handle_server_reply(info, header);
        bzero(&header, sizeof(server_reply_t));
    }
    return (CLIENT_SUCCESS);
}