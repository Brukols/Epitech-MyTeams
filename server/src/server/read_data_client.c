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

static int add_response(client_t *client)
{
    header_t header = {231, strlen(response)};
    bool ret;

    client->close = true;
    ret = smart_buffer_add_data(client->write_buf, &header, sizeof(header_t));
    if (!ret)
        return (FAILURE);
    ret = smart_buffer_add_string(client->write_buf, response);
    if (!ret)
        return (FAILURE);
    return (SUCCESS);
}

int read_data_client(server_t *server, client_t *client)
{
    char buffer[256] = {0};
    ssize_t len = read(client->fd, buffer, 255);

    if (len == 0) {
        add_response(client);
    }
    smart_buffer_add_string(client->read_buf, buffer);
    (void)server;
    return (0);
}