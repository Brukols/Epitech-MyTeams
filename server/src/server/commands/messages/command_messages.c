/*
** EPITECH PROJECT, 2020
** my teams
** File description:
** messages command
*/

#include "user.h"
#include "server.h"
#include "message.h"

static int add_message_to_client_buffer(
    client_t *client,
    message_t *msg,
    bool *sent
    )
{
    if (!msg)
        return (SUCCESS);
    *sent = true;
    if (send_header_reply(PRINT_PRIVATE_MESSAGES,
        sizeof(uuid_t) + sizeof(time_t) + DEFAULT_BODY_LENGTH, client))
        return (FAILURE);
    if (!smart_buffer_add_data(
        client->write_buf, &msg->user_uuid, sizeof(uuid_t)))
        return (FAILURE);
    if (!smart_buffer_add_data(client->write_buf, &msg->time, sizeof(time_t)))
        return (FAILURE);
    if (!smart_buffer_add_data(client->write_buf, &msg->message,
        DEFAULT_BODY_LENGTH))
        return (FAILURE);
    return (SUCCESS);
}

static message_t *get_next_message_with_uuid(list_t *list, uuid_t uuid)
{
    message_t *msg = NULL;

    if (!*list)
        return (NULL);
    msg = (*list)->value;
    while (*list && uuid_compare(uuid, msg->user_uuid)) {
        *list = (*list)->next;
        msg = (*list)->value;
    }
    if (!*list)
        return (NULL);
    return (msg);
}

static int send_messages(client_t *cli, user_t *user2, bool *sent)
{
    list_t m_list1 = cli->user->messages;
    list_t m_list2 = user2 != cli->user ? user2->messages : NULL;
    message_t *msg = NULL;

    for (; m_list1 || m_list2; msg = NULL) {
        message_t *msg1 = get_next_message_with_uuid(&m_list1, user2->uuid);
        message_t *msg2 = get_next_message_with_uuid(&m_list2, cli->user->uuid);

        if (m_list1 && (!m_list2 || msg1->time < msg2->time)) {
            msg = msg1;
            m_list1 = m_list1->next;
        } else if (m_list2) {
            msg = msg2;
            m_list2 = m_list2->next;
        }
        if (add_message_to_client_buffer(cli, msg, sent) != SUCCESS)
            return (FAILURE);
    }
    return (SUCCESS);
}

int command_messages(
    server_t *server,
    client_t *client,
    client_request_t *req,
    char *data
    )
{
    bool sent = false;
    char *not_found = "No messages found";
    user_t *user2 = NULL;

    if (req->message_size != 16)
        return (send_error_arguments(client, "Invalid argument size"));
    user2 = user_get_by_uuid(server->users, (unsigned char *)data);
    if (!user2)
        return (send_unknown(client, UNKNOWN_USER, (unsigned char *)data));
    if (send_messages(client, user2, &sent) == FAILURE)
        return (FAILURE);
    if (!sent)
        if (send_reply(client, COMMAND_OK, not_found) == FAILURE)
            return (FAILURE);
    return (SUCCESS);
}
