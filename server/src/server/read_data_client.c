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

static bool if_good_reply(smart_buffer_t *buffer, void *data)
{
    client_request_t *reply = data;

    if (smart_buffer_get_size(buffer) >= reply->message_size + \
sizeof(client_request_t))
        return (true);
    return (false);
}

int read_data_client(server_t *server, client_t *client)
{
    ssize_t len = smart_buffer_read(client->read_buf, client->fd);
    client_request_t reply = {0};
    char *message;

    if (len == 0) {
        command_logout(server, client, NULL, NULL);
        return (0);
    }
    if (smart_buffer_get_data_if(client->read_buf, &reply, \
sizeof(client_request_t), &if_good_reply) == false)
        return (SUCCESS);
    message = malloc(reply.message_size);
    if (!message)
        return (FAILURE);
    smart_buffer_get_data(client->read_buf, message, reply.message_size);
    if (translate_data_client(server, client, &reply, message) < 0)
        return (FAILURE);
    free(message);
    return (0);
}