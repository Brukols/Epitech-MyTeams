/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** command_subscribe
*/

#include "server.h"
#include "logging_server.h"

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
    char uuid_team[37];
    char uuid_user[37];

    if (user_is_in_team(client, team))
        return (send_reply(client, COMMAND_OK, "{SERVER} User already in the team"));
    if (!list_add_elem_at_back(&team->subscribers, client->user))
        return (FAILURE);
    uuid_unparse(client->user->uuid, uuid_user);
    uuid_unparse(team->uuid, uuid_team);
    server_event_user_join_a_team(uuid_team, uuid_user);
    if (send_header_reply(PRINT_SUBSCRIBED, 16 + 16, client) < 0)
        return (FAILURE);
    if (!smart_buffer_add_data(client->write_buf, client->user->uuid, 16))
        return (FAILURE);
    if (!smart_buffer_add_data(client->write_buf, team->uuid, 16))
        return (FAILURE);
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
    return (send_reply(client, BAD_SEQUENCE, "{SERVER} Unable to found uuid"));
}