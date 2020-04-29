/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** TODO: add description
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "myteams_client.h"

client_t *init_client()
{
    client_t *client = malloc(sizeof(client_t));

    if (!client) {
        fprintf(stdout, "./myteams_cli: initialisation failed\n");
        return (NULL);
    }
    client->user_in = user_new_message();
    client->user_out = user_new_message();
    client->server_in = smart_buffer_create();
    client->server_out = smart_buffer_create();
    if (!client->user_in || !client->user_out || !client->server_in || !client->server_out) {
        fprintf(stdout, "./myteams_cli: initialisation failed\n");
        return (NULL);
    }
    client->socket = -1;
    bzero(&client->server_infos, sizeof(struct sockaddr_in));
    client->close = false;
    return (client);
}