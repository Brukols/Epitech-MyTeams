/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** TODO: add description
*/

#include <stdlib.h>
#include <zconf.h>
#include "myteams_client.h"

void close_client(client_t *info)
{
    free(info->user_in);
    free(info->user_out);
    close(info->socket);
    free(info);
}