/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** translate_data_client
*/

#include "server.h"
#include "utils.h"

const commands_t commands[] = {
    {HELP, &command_help},
    {LOGIN, &command_login},
    {LOGOUT, &command_logout},
    {UNKNOWN, NULL}
};

int translate_data_client(server_t *server, client_t *client, client_request_t *reply, char *data)
{
    for (size_t i = 0; commands[i].code != UNKNOWN; i++) {
        if (commands[i].code != reply->command)
            continue;
        if (commands[i].fct(server, client, reply, data) < 0)
            return (FAILURE);
        return (SUCCESS);
    }
    return (FAILURE);
}