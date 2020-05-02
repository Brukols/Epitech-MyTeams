/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** command_use
*/

#include "server.h"

static void find_in_thread(channel_t *channel, client_t *client, uuid_t uuid)
{
    for (list_t threads = channel->threads; threads; threads = threads->next) {
        thread_t *thread = (thread_t *)(threads->value);

        client->thread = thread;
        if (!uuid_compare(thread->uuid, uuid))
            return;
    }
    client->thread = NULL;
}

static void find_in_channel(team_t *team, client_t *client, uuid_t uuid)
{
    for (list_t channels = team->channels; channels; \
channels = channels->next) {
        channel_t *channel = (channel_t *)(channels->value);

        client->channel = channel;
        if (!uuid_compare(channel->uuid, uuid))
            return;
        find_in_thread(channel, client, uuid);
        if (client->thread)
            return;
    }
    client->channel = NULL;
}

int command_use(server_t *server, client_t *client, client_request_t *req, \
char *data)
{
    uuid_t uuid;

    if (req->message_size == 0) {
        client->team = NULL;
        client->channel = NULL;
        client->thread = NULL;
        return (send_reply(client, COMMAND_OK, "{SERVER} /use command succeed"));
    }
    if (req->message_size != 16)
        return (send_error_arguments(client, "{SERVER} Wrong arguments"));
    memcpy(uuid, data, 16);
    for (list_t teams = server->teams; teams; teams = teams->next) {
        team_t *team = (team_t *)(teams->value);

        client->team = team;
        if (!uuid_compare(uuid, team->uuid))
            return (send_reply(client, COMMAND_OK, "{SERVER} Command /use ok"));
        find_in_channel(team, client, uuid);
        if (client->channel)
            return (send_reply(client, COMMAND_OK, "{SERVER} Command /use ok"));
    }
    client->team = NULL;
    return (send_reply(client, BAD_SEQUENCE, "{SERVER} Unable to found to matchin uuid"));
}