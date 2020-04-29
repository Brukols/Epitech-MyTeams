/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** TODO: add description
*/

#include <stdlib.h>
#include <zconf.h>
#include "client.h"

void close_client(client_t *info)
{
    if (info->client_io)
        free(info->client_io);
    if (info->server_io)
        free(info->server_io);
    close(info->socket);
    free(info);
}