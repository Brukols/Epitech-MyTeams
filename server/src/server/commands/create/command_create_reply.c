/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** command_create_reply
*/

#include "server.h"
#include "logging_server.h"

static int broadcast_thread_new_message(server_t *server, reply_t *reply, client_t *actual_client)
{
    for (list_t clients = server->client; clients; clients = clients->next) {
        client_t *client = (client_t *)(clients->value);

        if (!client->user)
            continue;
        if (send_header_reply(EVENT_TEAM_CREATED, 16 + 16 + 16 + DEFAULT_BODY_LENGTH, client) < 0)
            return (FAILURE);
        if (!smart_buffer_add_data(client->write_buf, actual_client->team->uuid, 16))
            return (FAILURE);
        if (!smart_buffer_add_data(client->write_buf, actual_client->thread->uuid, 16))
            return (FAILURE);
        if (!smart_buffer_add_data(client->write_buf, reply->user->uuid, 16))
            return (FAILURE);
        if (!smart_buffer_add_data(client->write_buf, reply->message, DEFAULT_BODY_LENGTH))
            return (FAILURE);
    }
    return (SUCCESS);
}

int command_create_reply(server_t *server, client_t *client, client_request_t *req, char *data)
{
    char *comment = data;
    reply_t *reply;
    char uuid_thread[37];
    char uuid_user[37];

    if (req->message_size != DEFAULT_BODY_LENGTH)
        return (send_error_arguments(client, "Wrong arguments"));
    reply = create_reply(comment);
    if (!list_add_elem_at_back(&client->thread->replies, reply))
        return (FAILURE);
    reply->user = client->user;
    uuid_unparse(client->thread->uuid, uuid_thread);
    uuid_unparse(client->user->uuid, uuid_user);
    server_event_thread_new_message(uuid_thread, uuid_user, comment);
    return (broadcast_thread_new_message(server, reply, client));
}