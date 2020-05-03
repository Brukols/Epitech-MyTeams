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
#include "saving.h"
#include <stdio.h>

static void del_it_at_position(list_t *client, list_t *it, client_t *tmp, \
int i)
{
    *it = (*it)->next;
    if (tmp->user)
        tmp->user->nb_clients--;
    list_del_elem_at_position(client, i, &delete_client);
}

static bool init_fds_client(list_t *client, fd_set *readfs, fd_set *writefs)
{
    list_t it = *client;
    int i = 0;

    while (it) {
        client_t *tmp = ((client_t *)(it->value));

        if (smart_buffer_get_size(tmp->write_buf) == 0 && tmp->close) {
            del_it_at_position(client, &it, tmp, i);
            continue;
        }
        if (smart_buffer_get_size(tmp->write_buf) != 0)
            FD_SET(tmp->fd, writefs);
        if (!tmp->close)
            FD_SET(tmp->fd, readfs);
        it = it->next;
        i++;
    }
    return (true);
}

static void init_fds(server_t *server, fd_set *readfs, fd_set *writefs)
{
    FD_ZERO(readfs);
    FD_ZERO(writefs);
    FD_SET(server->fd, readfs);

    init_fds_client(&server->client, readfs, writefs);
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
    save_server(server);
    delete_server(server);
    return (0);
}
