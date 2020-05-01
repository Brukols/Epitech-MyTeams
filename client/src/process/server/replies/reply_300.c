/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** TODO: add description
*/

#include <uuid/uuid.h>
#include "myteams_client.h"
#include "logging_client.h"

int reply_300(client_t *info, server_reply_t *header)
{
    char username[32 + 1] = {0};
    unsigned char uuid[16 + 1] = {0};
    char unparse_uuid[37] = {0};

    if (!smart_buffer_get_data(info->server_out, &username, 32))
        return (CLIENT_ERROR);
    if (!smart_buffer_get_data(info->server_out, &uuid, 16))
        return (CLIENT_ERROR);
    uuid_unparse(uuid, unparse_uuid);
    client_event_loggedin(unparse_uuid, username);
    return (CLIENT_SUCCESS);
}