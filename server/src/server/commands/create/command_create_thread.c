/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** command_create_thread
*/

#include "server.h"
#include "logging_server.h"

static int add_data_in_client(client_t *client, thread_t *thread, \
enum reply_code_e code)
{
    if (send_header_reply(code, 16 + 16 + sizeof(long) + \
DEFAULT_NAME_LENGTH + DEFAULT_BODY_LENGTH, client) < 0)
        return (FAILURE);
    if (!smart_buffer_add_data(client->write_buf, thread->uuid, 16))
        return (FAILURE);
    if (!smart_buffer_add_data(client->write_buf, thread->user->uuid, 16))
        return (FAILURE);
    if (!smart_buffer_add_data(client->write_buf, &thread->time, sizeof(long)))
        return (FAILURE);
    if (!smart_buffer_add_data(client->write_buf, thread->title, \
DEFAULT_NAME_LENGTH))
        return (FAILURE);
    if (!smart_buffer_add_data(client->write_buf, thread->message, \
DEFAULT_BODY_LENGTH))
        return (FAILURE);
    return (SUCCESS);
}

static int broadcast_thread_created(server_t *server, thread_t *thread, \
client_t *actual_client)
{
    int ret;

    for (list_t clients = server->client; clients; clients = clients->next) {
        client_t *client = (client_t *)(clients->value);

        if (!client->user)
            continue;
        if (client == actual_client)
            ret = add_data_in_client(client, thread, PRINT_THREAD_CREATED);
        else
            ret = add_data_in_client(client, thread, EVENT_THREAD_CREATED);
        if (ret < 0)
            return (FAILURE);
    }
    return (SUCCESS);
}

int command_create_thread(server_t *server, client_t *client, \
client_request_t *req, char *data)
{
    char title[DEFAULT_NAME_LENGTH] = {0};
    char message[DEFAULT_BODY_LENGTH] = {0};
    thread_t *thread;
    char uuid_channel[37];
    char uuid_thread[37];
    char uuid_user[37];

    if (get_args_title_message(title, message, req, data) < 0)
        return (send_error_arguments(client, \
"{SERVER} /create wrong arguments"));
    thread = create_thread(title, message);
    if (!thread)
        return (FAILURE);
    if (!list_add_elem_at_back(&client->channel->threads, thread))
        return (FAILURE);
    thread->user = client->user;
    client->thread = thread;
    uuid_unparse(client->channel->uuid, uuid_channel);
    uuid_unparse(client->thread->uuid, uuid_thread);
    uuid_unparse(client->user->uuid, uuid_user);
    server_event_thread_created(uuid_channel, uuid_thread, uuid_user, message);
    return (broadcast_thread_created(server, thread, client));
}