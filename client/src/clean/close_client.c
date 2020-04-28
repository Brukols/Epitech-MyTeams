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
    close(info->socket);
    free(info);
}