/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** command_use
*/

#include "server.h"
#include "reply_code.h"

static int find_in_thread(channel_t *channel, client_t *client, char *data)
{
    uuid_t uuid;

    memcpy(uuid, data + (sizeof(uuid_t) * 2), sizeof(uuid_t));
    for (list_t threads = channel->threads; threads; threads = threads->next) {
        thread_t *thread = (thread_t *)(threads->value);

        if (uuid_compare(thread->uuid, uuid))
            continue;
        client->thread = thread;
        return (send_reply(client, COMMAND_OK, \
"{SERVER} Command /use ok"));
    }
    return (send_unknown(client, UNKNOWN_THREAD, uuid));
}

static int find_in_channel(team_t *team, client_t *client, \
client_request_t *req, char *data)
{
    uuid_t uuid;

    memcpy(uuid, data + sizeof(uuid_t), sizeof(uuid_t));
    for (list_t channels = team->channels; channels; \
channels = channels->next) {
        channel_t *channel = (channel_t *)(channels->value);

        if (uuid_compare(channel->uuid, uuid))
            continue;
        client->channel = channel;
        if (req->message_size >= (int)(sizeof(uuid_t) * 3))
            return (find_in_thread(channel, client, data));
        client->thread = NULL;
        return (send_reply(client, COMMAND_OK, \
"{SERVER} Command /use ok"));
    }
    return (send_unknown(client, UNKNOWN_CHANNEL, uuid));
}

static int find_in_team(server_t *server, client_t *client, \
client_request_t *req, char *data)
{
    uuid_t uuid;

    memcpy(uuid, data, sizeof(uuid_t));
    for (list_t teams = server->teams; teams; teams = teams->next) {
        team_t *team = (team_t *)(teams->value);

        if (uuid_compare(uuid, team->uuid))
            continue;
        client->team = team;
        if (req->message_size >= (int)(sizeof(uuid_t) * 2))
            return (find_in_channel(team, client, req, data));
        client->channel = NULL;
        client->thread = NULL;
        return (send_reply(client, COMMAND_OK, \
"{SERVER} Command /use ok"));
    }
    return (send_unknown(client, UNKNOWN_TEAM, uuid));
}

int command_use(server_t *server, client_t *client, client_request_t *req, \
char *data)
{
    if (req->message_size == 0) {
        client->team = NULL;
        client->channel = NULL;
        client->thread = NULL;
        return (send_reply(client, COMMAND_OK, \
"[SERVER] /use: succeed"));
    }
    if (req->message_size % sizeof(uuid_t) != 0)
        return (send_reply(client, BAD_SEQUENCE, \
"{SERVER} Unable to found to matchin uuid"));
    return (find_in_team(server, client, req, data));
}