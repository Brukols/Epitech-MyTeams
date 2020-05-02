/*
** EPITECH PROJECT, 2020
** my teams
** File description:
** messages command
*/

#include "user.h"
#include "server.h"
#include "message.h"

static int send_messages(client_t *client, uuid_t data, bool *sent)
{
    for (list_t msg = client->user->messages; msg; msg = msg->next) {
        message_t *message = msg->value;
        if (uuid_compare((unsigned char *)data, message->user_uuid))
            continue;
        *sent = true;
        if (send_header_reply(
                PRINT_PRIVATE_MESSAGES,
                sizeof(time_t) + DEFAULT_BODY_LENGTH, client))
            return (FAILURE);
        if (!smart_buffer_add_data(
                client->write_buf, &message->time, sizeof(time_t)))
            return (FAILURE);
        if (!smart_buffer_add_data(
                client->write_buf, &message->message, DEFAULT_BODY_LENGTH))
            return (FAILURE);
    }
    return (SUCCESS);
}

int command_messages(
    server_t *server, client_t *client, client_request_t *req, char *data)
{
    bool sent = false;
    char *not_found = "No messages found";

    if (req->message_size != 16)
        return (send_error_arguments(client, "Invalid argument size"));
    if (!user_get_by_uuid(server->users, (unsigned char *)data))
        return (send_unknown(client, UNKNOWN_USER, (unsigned char *)data));
    if (send_messages(client, (unsigned char *)data, &sent) == FAILURE)
        return (FAILURE);
    if (!sent)
        if (send_reply(client, COMMAND_OK, not_found) == FAILURE)
            return (FAILURE);
    return (SUCCESS);
}
