/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** TODO: add description
*/

#include <uuid/uuid.h>
#include "myteams_client.h"
#include "logging_client.h"

int reply_253(client_t *info, server_reply_t *header)
{
    unsigned char thread_uuid[16 + 1] = {0};
    char thread_unparse_uuid[36 + 1] = {0};
    unsigned char user_uuid[16 + 1] = {0};
    char user_unparse_uuid[36 + 1] = {0};
    time_t reply_timestamp = 0;
    char reply_body[512 + 1] = {0};
    (void)header;

    if (!smart_buffer_get_data(info->server_out, &thread_uuid, 16)
        || !smart_buffer_get_data(info->server_out, &user_uuid, 16)
        || !smart_buffer_get_data(info->server_out, &reply_timestamp, sizeof(time_t))
        || !smart_buffer_get_data(info->server_out, &reply_body, 512))
        return (CLIENT_ERROR);
    uuid_unparse(thread_uuid, thread_unparse_uuid);
    uuid_unparse(user_uuid, user_unparse_uuid);
    client_print_reply_created(thread_unparse_uuid, user_unparse_uuid,
                        reply_timestamp, reply_body);
    return (CLIENT_SUCCESS);
}