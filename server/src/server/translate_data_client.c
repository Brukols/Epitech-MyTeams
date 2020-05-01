/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** translate_data_client
*/

#include "server.h"
#include "utils.h"

const commands_t not_logged_in_commands[] = {
    {HELP, &command_help},
    {LOGIN, &command_login},
    {LOGOUT, &command_logout},
    {UNKNOWN, NULL}
};

const commands_t commands[] = {
    {USER, &command_user},
    {USERS, &command_users},
    {MESSAGES, &command_messages},
    {UNKNOWN, NULL}
};

int translate_data_client(
    server_t *server, client_t *client, client_request_t *reply, char *data)
{
    for (size_t i = 0; not_logged_in_commands[i].code != UNKNOWN; i++) {
        if (not_logged_in_commands[i].code != reply->command)
            continue;
        if (not_logged_in_commands[i].fct(server, client, reply, data) < 0)
            return (FAILURE);
        return (SUCCESS);
    }
    for (size_t i = 0; commands[i].code != UNKNOWN; i++) {
        if (!client_is_logged_in(client) || commands[i].code != reply->command)
            continue;
        if (commands[i].fct(server, client, reply, data) < 0)
            return (FAILURE);
        return (SUCCESS);
    }
    return (FAILURE);
}
