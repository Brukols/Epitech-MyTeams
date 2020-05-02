/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** command_subscribe
*/

#include "server.h"

static bool user_is_in_team(client_t *client, team_t *team)
{
    for (list_t users = team->subscribers; users; users = users->next) {
        if (users->value == client->user)
            return (true);
    }
    return (false);
}

static int subscribe_user_to_team(client_t *client, team_t *team)
{
    if (user_is_in_team(client, team))
        return (SUCCESS);
    if (!list_add_elem_at_back(&team->subscribers, client->user))
        return (false);
    return (SUCCESS);
}

int command_subscribe(server_t *server, client_t *client, \
client_request_t *req, char *data)
{
    uuid_t uuid;
    if (req->message_size != 16)
        return (send_error_arguments(client, "{SERVER} Wrong arguments"));
    memcpy(uuid, data, 16);
    for (list_t teams = server->teams; teams; teams = teams->next) {
        team_t *team = (team_t *)(teams->value);

        if (!uuid_compare(uuid, team->uuid))
            return (subscribe_user_to_team(client, team));
    }
    // Send error unknown team
    return (SUCCESS);
}