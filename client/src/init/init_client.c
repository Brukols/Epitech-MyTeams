/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** TODO: add description
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "client.h"

client_t *init_client()
{
    client_t *client = malloc(sizeof(client_t));

    if (!client) {
        fprintf(stderr, "./myteams_cli: initialisation failed\n");
        return (NULL);
    }
    client->socket = -1;
    bzero(&client->server_infos, sizeof(struct sockaddr_in));
    return (client);
}