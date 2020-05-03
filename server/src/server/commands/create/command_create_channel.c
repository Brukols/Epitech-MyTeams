/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** command_create_channel
*/

#include "server.h"
#include "logging_server.h"

static bool name_already_exist(char *name, client_t *client)
{
    for (list_t channels = client->team->channels; channels; \
channels = channels->next) {
        channel_t *channel = (channel_t *)(channels->value);

        if (!strcmp(channel->name, name))
            return (true);
    }
    return (false);
}

static int add_data_in_client(client_t *client, channel_t *channel, \
enum reply_code_e code)
{
    if (send_header_reply(code, 16 + DEFAULT_NAME_LENGTH + \
DEFAULT_DESCRIPTION_LENGTH, client) < 0)
        return (FAILURE);
    if (!smart_buffer_add_data(client->write_buf, channel->uuid, 16))
        return (FAILURE);
    if (!smart_buffer_add_data(client->write_buf, channel->name, \
DEFAULT_NAME_LENGTH))
        return (FAILURE);
    if (!smart_buffer_add_data(client->write_buf, channel->description, \
DEFAULT_DESCRIPTION_LENGTH))
        return (FAILURE);
    return (SUCCESS);
}

static int broadcast_channel_created(server_t *server, channel_t *channel, \
client_t *actual_client)
{
    int ret;

    for (list_t clients = server->client; clients; clients = clients->next) {
        client_t *client = (client_t *)(clients->value);

        if (!client->user || !user_is_in_team(client, actual_client->team))
            continue;
        if (client == actual_client)
            ret = add_data_in_client(client, channel, PRINT_CHANNEL_CREATED);
        else
            ret = add_data_in_client(client, channel, EVENT_CHANNEL_CREATED);
        if (ret < 0)
            return (FAILURE);
    }
    return (SUCCESS);
}

int command_create_channel(server_t *server, client_t *client, \
client_request_t *req, char *data)
{
    char name[DEFAULT_NAME_LENGTH] = {0};
    char description[DEFAULT_DESCRIPTION_LENGTH] = {0};
    channel_t *channel;
    char uuid_team[37];
    char uuid_channel[37];

    if (!user_is_in_team(client, client->team))
        return (send_reply(client, UNAUTHORIZED, NULL));
    if (get_args_name_description(name, description, req, data) == FAILURE)
        return (send_error_arguments(client, \
"{SERVER} /create wrong arguments"));
    if (name_already_exist(name, client))
        return (send_error_already_exist(client));
    channel = create_channel(name, description);
    if (!channel)
        return (FAILURE);
    if (!list_add_elem_at_back(&client->team->channels, channel))
        return (FAILURE);
    uuid_unparse(client->team->uuid, uuid_team);
    uuid_unparse(channel->uuid, uuid_channel);
    server_event_channel_created(uuid_team, uuid_channel, channel->name);
    return (broadcast_channel_created(server, channel, client));
}