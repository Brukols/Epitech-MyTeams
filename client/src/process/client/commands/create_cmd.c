/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** TODO: add description
*/

#include "myteams_client.h"
#include "reply_code.h"

static int create_cmd_team_channel(client_t *info, char *name, char *description)
{
    client_request_t header = {CREATE, 32 + 255};
    bool ret;

    ret = smart_buffer_add_data(info->server_in, &header, sizeof(client_request_t));
    if (!ret) return (CLIENT_ERROR);
    ret = smart_buffer_add_data(info->server_in, &name, 32);
    if (!ret) return (CLIENT_ERROR);
    ret = smart_buffer_add_data(info->server_in, &description, 255);
    if (!ret) return (CLIENT_ERROR);
    return (CLIENT_SUCCESS);
}

static int create_cmd_thread(client_t *info, char *name, char *message)
{
    client_request_t header = {CREATE, 32 + 512};
    bool ret;

    ret = smart_buffer_add_data(info->server_in, &header, sizeof(client_request_t));
    if (!ret) return (CLIENT_ERROR);
    ret = smart_buffer_add_data(info->server_in, &name, 32);
    if (!ret) return (CLIENT_ERROR);
    ret = smart_buffer_add_data(info->server_in, &message, 512);
    if (!ret) return (CLIENT_ERROR);
    return (CLIENT_SUCCESS);
}

static int create_cmd_others(client_t *info, const char *cmd)
{
    char name[32 + 1] = {0};
    char description[255 + 1] = {0};
    char message[512 + 1] = {0};

    if (!get_arg(cmd, name, 32, 0))
        return (CLIENT_ERROR);
    if (get_arg(cmd, description, 255, 1))
        return (create_cmd_team_channel(info, name, message));
    if (get_arg(cmd, message, 512, 1))
        return (create_cmd_thread(info, name, message));
    return (CLIENT_ERROR);
}

static int create_cmd_comment_only(client_t *info, const char *cmd)
{
    client_request_t header = {CREATE, 512};
    char comment[512 + 1] = {0};
    bool ret;

    if (!get_arg(cmd, comment, 512, 0))
        return (CLIENT_ERROR);
    ret = smart_buffer_add_data(info->server_in, &header, sizeof(client_request_t));
    if (!ret) return (CLIENT_ERROR);
    ret = smart_buffer_add_data(info->server_in, &comment, 512);
    if (!ret) return (CLIENT_ERROR);
    return (CLIENT_SUCCESS);
}

int create_cmd(client_t *info, char *cmd)
{
    if (get_arg_nb(cmd) > 2)
        return (CLIENT_ERROR);
    if (get_arg_nb(cmd) == 1)
        return (create_cmd_comment_only(info, cmd));
    return (create_cmd_others(info, cmd));
}