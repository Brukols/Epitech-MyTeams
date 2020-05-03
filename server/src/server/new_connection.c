/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** new_connection
*/

#include "server.h"
#include <stdio.h>
#include <arpa/inet.h>
#include "client.h"
#include <string.h>

static const char *response = "welcome";

int add_response(client_t *client)
{
    server_reply_t header = {200, strlen(response)};

    if (!smart_buffer_add_data(client->write_buf, &header, \
sizeof(server_reply_t)))
        return (FAILURE);
    if (!smart_buffer_add_string(client->write_buf, response))
        return (FAILURE);
    return (SUCCESS);
}

int new_connection(server_t *server)
{
    struct sockaddr_in addr;
    int fd = accept(server->fd, (struct sockaddr *)&addr, \
&(socklen_t){sizeof(addr)});
    client_t *client;

    if (fd < 0)
        return (FAILURE);
    printf("Connection from %s in port %d\n", inet_ntoa(addr.sin_addr), \
ntohs(addr.sin_port));
    client = create_client(fd);
    if (!client)
        return (FAILURE);
    if (list_add_elem_at_back(&server->client, client) == false)
        return (FAILURE);
    if (add_response(client) < 0)
        return (FAILURE);
    return (0);
}