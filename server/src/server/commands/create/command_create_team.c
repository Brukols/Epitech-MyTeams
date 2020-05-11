/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** command_create_team
*/

#include "server.h"
#include "logging_server.h"
#include <string.h>

static bool name_already_exist(char *name, server_t *server)
{
    for (list_t teams = server->teams; teams; teams = teams->next) {
        team_t *team = (team_t *)(teams->value);

        if (!strcmp(team->name, name))
            return (true);
    }
    return (false);
}

static int add_data_in_client(client_t *client, team_t *team, \
enum reply_code_e code)
{
    if (send_header_reply(code, 16 + \
DEFAULT_NAME_LENGTH + DEFAULT_DESCRIPTION_LENGTH, client) < 0)
        return (FAILURE);
    if (!smart_buffer_add_data(client->write_buf, team->uuid, 16))
        return (FAILURE);
    if (!smart_buffer_add_data(client->write_buf, team->name, \
DEFAULT_NAME_LENGTH))
        return (FAILURE);
    if (!smart_buffer_add_data(client->write_buf, team->description, \
DEFAULT_DESCRIPTION_LENGTH))
        return (FAILURE);
    return (SUCCESS);
}

static int broadcast_team_created(server_t *server, team_t *team, \
client_t *actual_client)
{
    int rvalue;

    for (list_t clients = server->client; clients; clients = clients->next) {
        client_t *client = (client_t *)(clients->value);

        if (!client->user)
            continue;
        if (client == actual_client)
            rvalue = add_data_in_client(client, team, PRINT_TEAM_CREATED);
        else
            rvalue = add_data_in_client(client, team, EVENT_TEAM_CREATED);
        if (rvalue < 0)
            return (FAILURE);
    }
    return (SUCCESS);
}

int command_create_team(server_t *server, client_t *client, \
client_request_t *req, char *data)
{
    char name[DEFAULT_NAME_LENGTH] = {0};
    char description[DEFAULT_DESCRIPTION_LENGTH] = {0};
    team_t *team = NULL;
    char uuid_team[37];
    char uuid_user[37];

    if (get_args_name_description(name, description, req, data) == FAILURE)
        return (send_error_arguments(client, \
"[SERVER] /create: wrong arguments"));
    if (name_already_exist(name, server))
        return (send_error_already_exist(client));
    team = create_team(name, description);
    if (!team)
        return (FAILURE);
    if (!list_add_elem_at_back(&server->teams, team))
        return (FAILURE);
    uuid_unparse(team->uuid, uuid_team);
    uuid_unparse(client->user->uuid, uuid_user);
    server_event_team_created(uuid_team, team->name, uuid_user);
    return (broadcast_team_created(server, team, client));
}