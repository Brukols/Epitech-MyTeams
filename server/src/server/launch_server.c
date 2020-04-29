/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** launch_server
*/

#include "server.h"
#include "my_teams.h"
#include "client.h"
#include "user.h"
#include <unistd.h>
#include <sys/signal.h>

static void init_fds_client(list_t it_client, fd_set *readfs, fd_set *writefs)
{
    for (; it_client; it_client = it_client->next) {
        client_t *client = ((client_t *)(it_client->value));
        if (client->write_buf != NULL)
            FD_SET(client->fd, writefs);
        FD_SET(client->fd, readfs);
    }
}

static void init_fds(server_t *server, fd_set *readfs, fd_set *writefs)
{
    FD_ZERO(readfs);
    FD_ZERO(writefs);
    FD_SET(server->fd, readfs);

    init_fds_client(server->client, readfs, writefs);
    list_t it_user = server->users;
    for (; it_user; it_user = it_user->next) {
        init_fds_client(((user_t *)(it_user->value))->client, readfs, writefs);
    }
}

int launch_server(server_t *server)
{
    fd_set writefs;
    fd_set readfs;
    int rvalue;

    signal(SIGINT, sig_handler);
    while (terminate(false) == false) {
        init_fds(server, &readfs, &writefs);
        rvalue = select(FD_SETSIZE, &readfs, &writefs, NULL, NULL);
        if (terminate(false) == true)
            break;
        if (rvalue < 0)
            return (FAILURE);
        if (translate_select(server, &readfs, &writefs) < 0)
            return (FAILURE);
    }
    close(server->fd);
    return (0);
}