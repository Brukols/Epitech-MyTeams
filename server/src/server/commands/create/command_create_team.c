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
    if (!send_header_reply(code, 16 + \
DEFAULT_NAME_LENGTH + DEFAULT_DESCRIPTION_LENGTH, client))
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
    for (list_t clients = server->client; clients; clients = clients->next) {
        client_t *client = (client_t *)(clients->value);

        if (!client->user)
            continue;
        if (client == actual_client)
            add_data_in_client(client, team, PRINT_TEAM_CREATE);
        else
            add_data_in_client(client, team, EVENT_TEAM_CREATED);
    }
    return (SUCCESS);
}

static int get_args(char *name, char *description, client_request_t *req, \
char *data)
{
    int size_name = strnlen(data, req->message_size);
    int size_description;

    if (size_name == 0 || size_name >= DEFAULT_NAME_LENGTH)
        return (FAILURE);
    strncpy(name, data, size_name);
    size_description = strnlen(data + size_name + 1, req->message_size);
    if (size_description >= DEFAULT_DESCRIPTION_LENGTH)
        return (FAILURE);
    strncpy(description, data + size_name + 1, size_description);
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

    if (get_args(name, description, req, data) == FAILURE)
        return (send_error_arguments(client, \
"{SERVER} /create command : Wrong arguments"));
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