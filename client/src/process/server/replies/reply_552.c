/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** TODO: add description
*/

#include <uuid/uuid.h>
#include "myteams_client.h"
#include "logging_client.h"

int reply_552(client_t *info, server_reply_t *header)
{
    unsigned char channel_uuid[16 + 1] = {0};
    char channel_unparse_uuid[36 + 1] = {0};
    (void)header;

    if (!smart_buffer_get_data(info->server_out, &channel_uuid, 16))
        return (CLIENT_ERROR);
    uuid_unparse(channel_uuid, channel_unparse_uuid);
    client_error_unknown_channel(channel_unparse_uuid);
    return (CLIENT_SUCCESS);
}