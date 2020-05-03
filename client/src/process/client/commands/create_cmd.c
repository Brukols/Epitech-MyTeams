/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** TODO: add description
*/

#include "myteams_client.h"
#include "reply_code.h"

static int create_cmd_others(client_t *info, const char *cmd)
{
    client_request_t header = {CREATE, 0};
    int size1 = get_arg_size(cmd, 0);
    int size2 = get_arg_size(cmd, 1);
    char comment1[size1 + 1];
    char comment2[size2 + 1];
    bool ret;

    bzero(&comment1, size1 + 1);
    bzero(&comment2, size2 + 1);
    if (!get_arg(cmd, comment1, size1, 0) || !get_arg(cmd, comment2, size2, 1))
        return (CLIENT_ERROR);
    header.message_size = size1 + 1 + size2 + 1;
    ret = smart_buffer_add_data(info->server_in, &header, sizeof
    (client_request_t));
    if (!ret) return (CLIENT_ERROR);
    ret = smart_buffer_add_data(info->server_in, &comment1, size1 + 1);
    if (!ret) return (CLIENT_ERROR);
    ret = smart_buffer_add_data(info->server_in, &comment2, size2 + 1);
    if (!ret) return (CLIENT_ERROR);
    return (CLIENT_SUCCESS);
}

static int create_cmd_comment_only(client_t *info, const char *cmd)
{
    client_request_t header = {CREATE, 0};
    int size = get_arg_size(cmd, 0);
    char comment[size + 1];
    bool ret;

    bzero(&comment, size + 1);
    if (!get_arg(cmd, comment, size, 0))
        return (CLIENT_ERROR);
    header.message_size = size + 1;
    ret = smart_buffer_add_data(info->server_in, &header, sizeof
    (client_request_t));
    if (!ret) return (CLIENT_ERROR);
    ret = smart_buffer_add_data(info->server_in, &comment, size + 1);
    if (!ret) return (CLIENT_ERROR);
    return (CLIENT_SUCCESS);
}

int create_cmd(client_t *info, const char *cmd)
{
    int arg_nb = get_arg_nb(cmd);
    if (arg_nb > 2 || arg_nb < 1)
        return (CLIENT_ERROR);
    if (arg_nb == 1)
        return (create_cmd_comment_only(info, cmd));
    return (create_cmd_others(info, cmd));
}