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

int handle_server_activities(client_t *info)
{
    server_reply_t reply = {0};

    if (smart_buffer_get_data_if(info->server_out, &reply, sizeof(server_reply_t), &if_good_reply) == false)
        return (CLIENT_SUCCESS);
    for (int i = 0; replies[i].code; i++) {
        if (reply.reply == replies[i].code) {
            return (replies[i].ft(info, &reply));
        }
    }
    //Display defaut return code
    return (CLIENT_SUCCESS);
}