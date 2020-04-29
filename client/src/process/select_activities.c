/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** TODO: add description
*/

#include <stdlib.h>
#include <stdio.h>
#include "client.h"

static void set_fd_set(client_t *info)
{
    FD_ZERO(&info->reads);
    FD_ZERO(&info->writes);
    FD_ZERO(&info->excepts);
    FD_SET(0, &info->reads);
    FD_SET(info->socket, &info->reads);

    //if (message à écrire sur à serveur)
    //    FD_SET(info->socket, &info->writes);
    //if (message à écrire sur stdout)
    //    FD_SET(1, &info->writes);

    FD_SET(0, &info->excepts);
    FD_SET(1, &info->excepts);
    FD_SET(info->socket, &info->excepts);
}

int select_activities(client_t *info)
{
    set_fd_set(info);
    if (select(FD_SETSIZE, &info->reads, &info->writes, &info->excepts, NULL) == -1) {
        fprintf(stdout, "./myteams_cli: Critic error\n");
        return (CLIENT_ERROR);
    }
    if (handle_io_activities(info) == CLIENT_ERROR)
        return (CLIENT_ERROR);
    return (CLIENT_SUCCESS);
}