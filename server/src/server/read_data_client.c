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
#include "my_teams.h"

static const char *response = "disconnection\n";

int read_data_client(server_t *server, client_t *client)
{
    char buffer[256] = {0};
    ssize_t len = read(client->fd, buffer, 255);

    if (len == 0) {
        client->close = true;
        client->write_buf = concat_buffer(client->write_buf, \
&(header_t){231, strlen(response)});
        client->write_buf = concat_buffer(client->write_buf, response);
    }
    (void)server;
    return (0);
}