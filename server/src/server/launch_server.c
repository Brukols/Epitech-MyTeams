/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** launch_server
*/

#include "server.h"
#include "client.h"
#include "user.h"
#include <unistd.h>
#include <sys/signal.h>
#include <string.h>

static bool init_fds_client(list_t *client, fd_set *readfs, fd_set *writefs)
{
    list_t it = *client;
    bool fs = true;

    while (it) {
        client_t *tmp = ((client_t *)(it->value));

        if (strlen(tmp->write_buf->buffer) == 0 && tmp->close) {
            list_del_elem_at_front(&it, &delete_client);
            if (fs)
                *client = it;
            continue;
        }
        if (strlen(tmp->write_buf->buffer) != 0)
            FD_SET(tmp->fd, writefs);
        if (!tmp->close)
            FD_SET(tmp->fd, readfs);
        it = it->next;
        fs = false;
    }
    return (true);
}

static void init_fds(server_t *server, fd_set *readfs, fd_set *writefs)
{
    FD_ZERO(readfs);
    FD_ZERO(writefs);
    FD_SET(server->fd, readfs);

    init_fds_client(&server->client, readfs, writefs);
    list_t it_user = server->users;
    for (; it_user; it_user = it_user->next) {
        init_fds_client(&((user_t *)(it_user->value))->client, readfs, writefs);
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
    delete_server(server);
    return (0);
}