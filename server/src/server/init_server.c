/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** init_server
*/

#include "server.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>

static struct sockaddr_in init_addr(int port)
{
    struct sockaddr_in addr;

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    return (addr);
}

static int prepare_server(server_t *server)
{
    if (setsockopt(server->fd, SOL_SOCKET, SO_REUSEADDR, &(int){1}, \
sizeof(int)) < 0)
        return (FAILURE);
    if (bind(server->fd, (struct sockaddr *)(&server->addr), \
sizeof(server->addr)) < 0)
        return (FAILURE);
    if (listen(server->fd, 10) < 0)
        return (FAILURE);
    return (SUCCESS);
}

server_t *init_server(char **av)
{
    server_t *server = malloc(sizeof(server_t));

    fprintf(stdout, "[SERVER] Initialisation start...\n");
    if (!server)
        return (NULL);
    server->port = atoi(av[1]);
    server->fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server->fd == -1)
        return (NULL);
    server->addr = init_addr(server->port);
    if (prepare_server(server) < 0)
        return (NULL);
    if (load_users(server) < 0)
        return (NULL);
    if (load_teams(server) < 0)
        return (NULL);
    server->client = NULL;
    fprintf(stdout, "[SERVER] Initialisation finish...\n");
    return (server);
}