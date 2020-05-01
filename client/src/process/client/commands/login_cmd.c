/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** TODO: add description
*/

#include "myteams_client.h"
#include "my_array.h"
#include "reply_code.h"
#include "requests.h"

int login_cmd(client_t *info, char *cmd)
{
    client_request_t header = {LOGIN, 32};
    char username[32 + 1] = {0};
    bool ret;
    if (!get_arg(cmd, username, 32, 0))
        return (CLIENT_ERROR);
    ret = smart_buffer_add_data(info->server_in, &header, sizeof(client_request_t));
    if (!ret) return (CLIENT_ERROR);
    ret = smart_buffer_add_data(info->server_in, &username, 32);
    if (!ret) return (CLIENT_ERROR);
    return (CLIENT_SUCCESS);
}