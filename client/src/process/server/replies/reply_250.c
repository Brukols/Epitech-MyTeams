/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** TODO: add description
*/

#include <uuid/uuid.h>
#include "myteams_client.h"
#include "logging_client.h"

int reply_250(client_t *info, server_reply_t *header)
{
    unsigned char team_uuid[16 + 1] = {0};
    char team_unparse_uuid[36 + 1] = {0};
    char team_name[32 + 1] = {0};
    char team_description[255 + 1] = {0};
    (void)header;

    if (!smart_buffer_get_data(info->server_out, &team_uuid, 16))
        return (CLIENT_ERROR);
    if (!smart_buffer_get_data(info->server_out, &team_name, 32))
        return (CLIENT_ERROR);
    if (!smart_buffer_get_data(info->server_out, &team_description, 255))
        return (CLIENT_ERROR);
    uuid_unparse(team_uuid, team_unparse_uuid);
    client_print_team_created(team_unparse_uuid, team_name, team_description);
    return (CLIENT_SUCCESS);
}