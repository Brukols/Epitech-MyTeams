/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** TODO: add description
*/

#include <uuid/uuid.h>
#include "myteams_client.h"
#include "reply_code.h"

static int use_cmd_check_arg(const char *cmd)
{
    char uuid[36 + 1] = {0};
    unsigned char parse_uuid[16 + 1] = {0};

    int nb_arg = get_arg_nb(cmd);
    if (nb_arg == -1 || nb_arg > 3)
        return (-1);
    for (int i = 0; i < nb_arg; i++) {
        if (get_arg_size(cmd, i) != 36)
            return (-1);
        if (!get_arg(cmd, uuid, 36, i))
            return (-1);
        if (uuid_parse(uuid, parse_uuid) == -1)
            return (-1);
    }
    return (nb_arg);
}

int use_cmd(client_t *info, const char *cmd)
{
    client_request_t header = {USE, 0};
    char uuid[36 + 1] = {0};
    unsigned char parse_uuid[16 + 1] = {0};
    bool ret;
    int nb_arg = use_cmd_check_arg(cmd);

    if (nb_arg == -1) return (CLIENT_ERROR);
    header.message_size = nb_arg * 16;
    ret = smart_buffer_add_data(info->server_in, &header, sizeof
    (client_request_t));
    if (!ret) return (CLIENT_ERROR);
    for (int i = 0; i < nb_arg; i++) {
        if (!get_arg(cmd, uuid, 36, i)) return (CLIENT_ERROR);
        if (uuid_parse(uuid, parse_uuid) == -1) return (CLIENT_ERROR);
        ret = smart_buffer_add_data(info->server_in, &parse_uuid, 16);
        if (!ret) return (CLIENT_ERROR);
    }
    return (CLIENT_SUCCESS);
}