/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** TODO: add description
*/

#include "myteams_client.h"
#include "reply_code.h"
#include "requests.h"

int help_cmd(client_t *info, char *cmd)
{
    client_request_t header = {HELP, 0};
    bool ret;
    ret = smart_buffer_add_data(info->server_in, &header, sizeof(client_request_t));
    if (!ret) return (CLIENT_ERROR);
    return (CLIENT_SUCCESS);
}