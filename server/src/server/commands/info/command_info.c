/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** command_info
*/

#include "server.h"

static int command_info_thread(client_t *client)
{
    if (send_header_reply(PRINT_THREAD, 16 + 16 + sizeof(time_t) + \
DEFAULT_NAME_LENGTH + DEFAULT_BODY_LENGTH, client) < 0)
        return (FAILURE);
    if (!smart_buffer_add_data(client->write_buf, client->thread->uuid, 16))
        return (FAILURE);
    if (!smart_buffer_add_data(client->write_buf, \
client->thread->user->uuid, 16))
        return (FAILURE);
    if (!smart_buffer_add_data(client->write_buf, &client->thread->time, \
sizeof(time_t)))
        return (FAILURE);
    if (!smart_buffer_add_data(client->write_buf, \
client->thread->title, DEFAULT_NAME_LENGTH))
        return (FAILURE);
    if (!smart_buffer_add_data(client->write_buf, \
client->thread->message, DEFAULT_BODY_LENGTH))
        return (FAILURE);
    return (SUCCESS);
}

static int command_info_channel(client_t *client)
{
    if (send_header_reply(PRINT_CHANNEL, 16 + DEFAULT_NAME_LENGTH + \
DEFAULT_DESCRIPTION_LENGTH, client) < 0)
        return (FAILURE);
    if (!smart_buffer_add_data(client->write_buf, client->channel->uuid, 16))
        return (FAILURE);
    if (!smart_buffer_add_data(client->write_buf, client->channel->name, \
DEFAULT_NAME_LENGTH))
        return (FAILURE);
    if (!smart_buffer_add_data(client->write_buf, \
client->channel->description, DEFAULT_DESCRIPTION_LENGTH))
        return (FAILURE);
    return (SUCCESS);
}

static int command_info_team(client_t *client)
{
    if (send_header_reply(PRINT_TEAM, 16 + DEFAULT_NAME_LENGTH + \
DEFAULT_DESCRIPTION_LENGTH, client) < 0)
        return (FAILURE);
    if (!smart_buffer_add_data(client->write_buf, client->team->uuid, 16))
        return (FAILURE);
    if (!smart_buffer_add_data(client->write_buf, client->team->name, \
DEFAULT_NAME_LENGTH))
        return (FAILURE);
    if (!smart_buffer_add_data(client->write_buf, \
client->team->description, DEFAULT_DESCRIPTION_LENGTH))
        return (FAILURE);
    return (SUCCESS);
}

static int command_info_user(client_t *client)
{
    if (send_header_reply(PRINT_USER, 16 + DEFAULT_NAME_LENGTH + 1, client) \
< 0)
        return (FAILURE);
    if (!smart_buffer_add_data(client->write_buf, client->user->uuid, 16))
        return (FAILURE);
    if (!smart_buffer_add_data(client->write_buf, client->user->username, \
DEFAULT_NAME_LENGTH))
        return (FAILURE);
    if (!smart_buffer_add_data(client->write_buf, \
&(char){client->user->nb_clients != 0}, 1))
        return (FAILURE);
    return (SUCCESS);
}

int command_info(server_t *server, client_t *client, client_request_t *req, \
char *data)
{
    (void)server;
    (void)req;
    (void)data;
    if (client->thread)
        return (command_info_thread(client));
    if (client->channel)
        return (command_info_channel(client));
    if (client->team)
        return (command_info_team(client));
    return (command_info_user(client));
}