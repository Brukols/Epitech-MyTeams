/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** TODO: add description
*/

#include <stdio.h>
#include "myteams_client.h"

static int handle_excepts_activities(client_t *info)
{
    if (FD_ISSET(0, &info->excepts)) {
        fprintf(stdout, "./myteams_cli: critical error with socket.\n");
        return (CLIENT_ERROR);
    }
    if (FD_ISSET(1, &info->excepts)) {
        fprintf(stdout, "./myteams_cli: critical error with socket.\n");
        return (CLIENT_ERROR);
    }
    if (FD_ISSET(info->socket, &info->excepts)) {
        fprintf(stdout, "./myteams_cli: critical error with socket.\n");
        return (CLIENT_ERROR);
    }
    return (CLIENT_SUCCESS);
}

static int handle_reads_activities(client_t *info)
{
    if (FD_ISSET(0, &info->reads)) {
        if (user_receive_message(0, info->user_in) == CLIENT_ERROR)
            info->close = true;
    }
    /*
    if (FD_ISSET(info->socket, &info->reads)) {
        if (tcp_receive_message(info->socket, info->server_io) == CLIENT_ERROR)
            info->close = true;
    }
     */
    return (CLIENT_SUCCESS);
}

static int handle_writes_activities(client_t *info)
{
    if (FD_ISSET(1, &info->writes)) {
        if (user_send_message(1, info->user_out) == CLIENT_ERROR) {
            fprintf(stdout, "./myteams_cli: critical error with socket.\n");
            return (CLIENT_ERROR);
        }
    }
    /*
    if (FD_ISSET(info->socket, &info->writes)) {
        if (tcp_send_message(info->socket, info->server_io) == CLIENT_ERROR) {
            fprintf(stdout, "./myteams_cli: critical error with socket.\n");
            return (CLIENT_ERROR);
        }
    }
     */
    return (CLIENT_SUCCESS);
}

int handle_io_activities(client_t *info)
{
    if (handle_excepts_activities(info) == CLIENT_ERROR)
        return (CLIENT_ERROR);
    if (handle_reads_activities(info) == CLIENT_ERROR)
        return (CLIENT_ERROR);
    if (handle_writes_activities(info) == CLIENT_ERROR)
        return (CLIENT_ERROR);
    return (CLIENT_SUCCESS);
}