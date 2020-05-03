/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** TODO: add description
*/

#include "myteams_client.h"

int run_client(client_t *info)
{
    while (!terminate(false) && !info->close) {
        if (select_activities(info) == CLIENT_ERROR)
            return (CLIENT_ERROR);
        if (handle_client_activities(info) == CLIENT_ERROR)
            return (CLIENT_ERROR);
        if (handle_server_activities(info) == CLIENT_ERROR)
            return (CLIENT_ERROR);
    }
    return (CLIENT_SUCCESS);
}