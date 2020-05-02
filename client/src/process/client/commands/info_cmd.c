/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** TODO: add description
*/

#include "myteams_client.h"
#include "reply_code.h"

int info_cmd(client_t *info, const char *cmd)
{
    client_request_t header = {INFO, 0};
    bool ret;
    (void)cmd;
    ret = smart_buffer_add_data(info->server_in, &header, sizeof(client_request_t));
    if (!ret) return (CLIENT_ERROR);
    return (CLIENT_SUCCESS);
}