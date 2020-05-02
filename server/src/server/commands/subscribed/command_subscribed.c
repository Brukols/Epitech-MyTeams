/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** command_subscribed
*/

#include "server.h"

static int list_all_teams(server_t *server, client_t *client)
{
    for (list_t teams = server->teams; teams; teams = teams->next) {
        team_t *team = (team_t *)(teams->value);

        if (send_header_reply(PRINT_TEAMS, 16 + DEFAULT_NAME_LENGTH + \
DEFAULT_DESCRIPTION_LENGTH, client) < 0)
            return (FAILURE);
        if (!smart_buffer_add_data(client->write_buf, team->uuid, 16))
            return (FAILURE);
        if (!smart_buffer_add_data(client->write_buf, team->name, \
DEFAULT_NAME_LENGTH))
            return (FAILURE);
        if (!smart_buffer_add_data(client->write_buf, team->description, \
DEFAULT_DESCRIPTION_LENGTH))
            return (FAILURE);
    }
    return (SUCCESS);
}

static team_t *get_team(server_t *server, uuid_t data)
{
    for (list_t teams = server->teams; teams; teams = teams->next) {
        team_t *team = (team_t *)(teams->value);

        if (!uuid_compare(data, team->uuid))
            return (team);
    }
    return (NULL);
}

static int list_all_user_subscribe(server_t *server, client_t *client, \
uuid_t data)
{
    team_t *team = get_team(server, data);

    if (!team)
        return (send_reply(client, BAD_SEQUENCE, "{SERVER} Wrong arguments"));
    for (list_t users = team->subscribers; users; users = users->next) {
        user_t *user = (user_t *)(users->value);

        if (send_header_reply(PRINT_USERS, 16 + DEFAULT_NAME_LENGTH + 1, \
client) < 0)
            return (FAILURE);
        if (!smart_buffer_add_data(client->write_buf, user->uuid, 16))
            return (FAILURE);
        if (!smart_buffer_add_data(client->write_buf, user->username, \
DEFAULT_NAME_LENGTH))
            return (FAILURE);
        if (!smart_buffer_add_data(client->write_buf, &(char){user->nb_clients != 0}, \
1))
            return (FAILURE);
    }
    return (SUCCESS);
}

int command_subscribed(server_t *server, client_t *client, \
client_request_t *req, char *data)
{
    uuid_t uuid;

    if (req->message_size == 0)
        return (list_all_teams(server, client));
    memcpy(uuid, data, 16);
    if (req->message_size == 16)
        return (list_all_user_subscribe(server, client, uuid));
    return (send_reply(client, SYNTAX_ERROR_ARGS, "{SERVER} Wrong arguments"));
}