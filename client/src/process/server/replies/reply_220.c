/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** TODO: add description
*/

#include <uuid/uuid.h>
#include "myteams_client.h"
#include "logging_client.h"

int reply_220(client_t *info, server_reply_t *header)
{
    unsigned char uuid[16 + 1] = {0};
    char unparse_uuid[36 + 1] = {0};
    time_t timestamp = 0;
    char message[512 + 1] = {0};
    (void)header;

    if (!smart_buffer_get_data(info->server_out, &uuid, 16))
        return (CLIENT_ERROR);
    if (!smart_buffer_get_data(info->server_out, &timestamp, sizeof(time_t)))
        return (CLIENT_ERROR);
    if (!smart_buffer_get_data(info->server_out, &message, 512))
        return (CLIENT_ERROR);
    uuid_unparse(uuid, unparse_uuid);
    client_private_message_print_messages(unparse_uuid, timestamp, message);
    return (CLIENT_SUCCESS);
}