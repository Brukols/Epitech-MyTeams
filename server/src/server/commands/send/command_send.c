/*
** EPITECH PROJECT, 2020
** my teams
** File description:
** send
*/

#include "message.h"
#include "server.h"
#include "user.h"

static bool get_arguments(
    client_request_t *req, char *data, uuid_t uuid, char *message)
{
    if (req->message_size != sizeof(uuid_t) + DEFAULT_BODY_LENGTH)
        return (false);
    memcpy(uuid, data, sizeof(uuid_t));
    memcpy(message, data + sizeof(uuid_t), DEFAULT_BODY_LENGTH);
    return (true);
}

static int broadcast_message_to_clients(
    list_t clients, uuid_t from, uuid_t to, char *msg)
{
    int size = sizeof(uuid_t) + DEFAULT_BODY_LENGTH;
    client_t *client = NULL;

    for (; clients; clients = clients->next) {
        client = clients->value;
        if (uuid_compare(client->user->uuid, to))
            continue;
        if (send_header_reply(EVENT_PRIVATE_MESSAGE_RECEIVED, size, client) < 0)
            return (FAILURE);
        if (!smart_buffer_add_data(client->write_buf, from, sizeof(uuid_t)))
            return (FAILURE);
        if (!smart_buffer_add_data(client->write_buf, msg, DEFAULT_BODY_LENGTH))
            return (FAILURE);
    }
    return (SUCCESS);
}

int command_send(
    server_t *server, client_t *client, client_request_t *req, char *data)
{
    uuid_t uuid;
    char message[512];
    user_t *user = NULL;

    if (get_arguments(req, data, uuid, message))
        return (send_error_arguments(client, "Invalid argument size"));
    user = user_get_by_uuid(server->users, uuid);
    if (!user)
        return (send_unknown(client, UNKNOWN_USER, uuid));
    return (broadcast_message_to_clients(
                server->client, client->user->uuid, uuid, message));
}
