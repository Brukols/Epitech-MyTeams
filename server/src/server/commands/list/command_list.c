/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** command_list
*/

#include "server.h"

static int command_list_replies(client_t *client)
{
    for (list_t replies = client->thread->replies; replies; replies = replies->next) {
        reply_t *reply = (reply_t *)(replies->value);

        if (send_header_reply(PRINT_REPLIES, 16 + 16 + sizeof(time_t) + \
DEFAULT_BODY_LENGTH, client) < 0)
            return (FAILURE);
        if (!smart_buffer_add_data(client->write_buf, client->thread->uuid, 16))
            return (FAILURE);
        if (!smart_buffer_add_data(client->write_buf, reply->user->uuid, 16))
            return (FAILURE);
        if (!smart_buffer_add_data(client->write_buf, &reply->time, sizeof(time_t)))
            return (FAILURE);
        if (!smart_buffer_add_data(client->write_buf, reply->message, DEFAULT_BODY_LENGTH))
            return (FAILURE);
    }
    return (SUCCESS);
}

static int command_list_threads(client_t *client)
{
    for (list_t threads = client->channel->threads; threads; threads = \
threads->next) {
        thread_t *thread = (thread_t *)(threads->value);

        if (send_header_reply(PRINT_THREADS, 16 + 16 + sizeof(time_t) + \
DEFAULT_NAME_LENGTH + DEFAULT_BODY_LENGTH, client) < 0)
            return (FAILURE);
        if (!smart_buffer_add_data(client->write_buf, thread->uuid, 16))
            return (FAILURE);
        if (!smart_buffer_add_data(client->write_buf, \
thread->user->uuid, 16))
            return (FAILURE);
        if (!smart_buffer_add_data(client->write_buf, &thread->time, \
sizeof(time_t)))
            return (FAILURE);
        if (!smart_buffer_add_data(client->write_buf, \
thread->title, DEFAULT_NAME_LENGTH))
            return (FAILURE);
        if (!smart_buffer_add_data(client->write_buf, \
thread->message, DEFAULT_BODY_LENGTH))
            return (FAILURE);
    }
    return (SUCCESS);
}

static int command_list_channels(client_t *client)
{
    for (list_t channels = client->team->channels; channels; channels = \
channels->next) {
        channel_t *channel = (channel_t *)(channels->value);

        if (send_header_reply(PRINT_CHANNELS, 16 + DEFAULT_NAME_LENGTH + \
DEFAULT_DESCRIPTION_LENGTH, client) < 0)
            return (FAILURE);
        if (!smart_buffer_add_data(client->write_buf, channel->uuid, 16))
            return (FAILURE);
        if (!smart_buffer_add_data(client->write_buf, channel->name, \
DEFAULT_NAME_LENGTH))
            return (FAILURE);
        if (!smart_buffer_add_data(client->write_buf, \
channel->description, DEFAULT_DESCRIPTION_LENGTH))
            return (FAILURE);
    }
    return (SUCCESS);
}

static int command_list_teams(server_t *server, client_t *client)
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
        if (!smart_buffer_add_data(client->write_buf, \
team->description, DEFAULT_DESCRIPTION_LENGTH))
            return (FAILURE);
    }
    return (SUCCESS);
}

int command_list(server_t *server, client_t *client, client_request_t *req, \
char *data)
{
    (void)server;
    (void)req;
    (void)data;
    if (client->thread)
        return (command_list_replies(client));
    if (client->channel)
        return (command_list_threads(client));
    if (client->team)
        return (command_list_channels(client));
    return (command_list_teams(server, client));
}