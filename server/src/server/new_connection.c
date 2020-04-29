/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** new_connection
*/

#include "server.h"
#include "my_teams.h"
#include <stdio.h>
#include <arpa/inet.h>
#include "client.h"

int new_connection(server_t *server)
{
    struct sockaddr_in client;
    int fd = accept(server->fd, (struct sockaddr *)&client, \
&(socklen_t){sizeof(client)});

    if (fd < 0)
        return (FAILURE);
    printf("Connection from %s in port %d\n", inet_ntoa(client.sin_addr), \
ntohs(client.sin_port));
    if (list_add_elem_at_back(&server->client, create_client(fd)) == false)
        return (FAILURE);
    return (0);
}