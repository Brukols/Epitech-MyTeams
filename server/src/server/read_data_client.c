/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** read_data_client
*/

#include "client.h"
#include <unistd.h>
#include "server.h"
#include <string.h>

static const char *response = "disconnection";

// For Disconnection
static int add_response(client_t *client)
{
    server_reply_t header = {231, strlen(response)};
    bool ret;

    client->close = true;
    ret = smart_buffer_add_data(client->write_buf, &header, sizeof(server_reply_t));
    if (!ret)
        return (FAILURE);
    ret = smart_buffer_add_string(client->write_buf, response);
    if (!ret)
        return (FAILURE);
    return (SUCCESS);
}

static bool if_good_reply(smart_buffer_t *buffer, void *data)
{
    client_request_t *reply = data;

    if (smart_buffer_get_size(buffer) >= reply->message_size + sizeof(client_request_t))
        return (true);
    return (false);
}

int read_data_client(server_t *server, client_t *client)
{
    ssize_t len = smart_buffer_read(client->read_buf, client->fd);
    client_request_t *reply = malloc(sizeof(client_request_t));
    char *message;

    if (!reply)
        return (FAILURE);
    if (len == 0) {
        client->close = true;
        return (0);
    }
    if (smart_buffer_get_data_if(client->read_buf, reply, sizeof(client_request_t), &if_good_reply) == false)
        return (SUCCESS);
    message = malloc(reply->message_size);
    if (!message)
        return (FAILURE);
    smart_buffer_get_data(client->read_buf, message, reply->message_size);
    free(reply);
    free(message);
    return (0);
}