/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** command_create_team
*/

#include "server.h"
#include "logging_server.h"

static bool name_already_exist(char *name, server_t *server)
{
    for (list_t teams = server->teams; teams; teams = teams->next) {
        team_t *team = (team_t *)(teams->value);

        if (!strcmp(team->name, name))
            return (true);
    }
    return (false);
}

static int broadcast_team_created(server_t *server, team_t *team)
{
    for (list_t clients = server->client; clients; clients = clients->next) {
        client_t *client = (client_t *)(clients->value);

        if (!client->user)
            continue;
        if (send_header_reply(EVENT_TEAM_CREATED, 16 + DEFAULT_NAME_LENGTH + DEFAULT_DESCRIPTION_LENGTH, client) < 0)
            return (FAILURE);
        if (!smart_buffer_add_data(client->write_buf, team->uuid, 16))
            return (FAILURE);
        if (!smart_buffer_add_data(client->write_buf, team->name, DEFAULT_NAME_LENGTH))
            return (FAILURE);
        if (!smart_buffer_add_data(client->write_buf, team->description, DEFAULT_DESCRIPTION_LENGTH))
            return (FAILURE);
    }
    return (SUCCESS);
}

int command_create_team(server_t *server, client_t *client, client_request_t *req, char *data)
{
    char name[DEFAULT_NAME_LENGTH] = {0};
    char description[DEFAULT_DESCRIPTION_LENGTH] = {0};
    team_t *team = NULL;
    char uuid_team[37];
    char uuid_user[37];

    if (req->message_size != DEFAULT_NAME_LENGTH + DEFAULT_DESCRIPTION_LENGTH)
        return (send_error_arguments(client, "Wrong arguments"));
    if (name_already_exist(name, server))
        return (send_error_already_exist(client));
    memcpy(name, data, DEFAULT_NAME_LENGTH);
    printf("Name : %s\n", name);
    memcpy(description, data + DEFAULT_NAME_LENGTH, DEFAULT_DESCRIPTION_LENGTH);
    printf("Description : %s\n", description);
    team = create_team(name, description);
    if (!list_add_elem_at_back(&server->teams, team))
        return (FAILURE);
    uuid_unparse(team->uuid, uuid_team);
    uuid_unparse(client->user->uuid, uuid_user);
    server_event_team_created(uuid_team, team->name, uuid_user);
    return (broadcast_team_created(server, team));
}