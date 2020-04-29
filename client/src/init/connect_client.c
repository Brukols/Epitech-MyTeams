/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** TODO: add description
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "client.h"

int connect_client(client_t *info, char *ip, char *port)
{
    int server_port = atoi(port);
    if ((info->socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stdout, "./myteams_cli: Client connection error\n");
        return (CLIENT_ERROR);
    }
    info->server_infos.sin_family = AF_INET;
    info->server_infos.sin_port = htons(server_port);
    if (inet_pton(AF_INET, ip, &info->server_infos.sin_addr) <= 0) {
        fprintf(stdout,
                "./myteams_cli: Invalid address/Address not supported\n");
        return (CLIENT_ERROR);
    }
    if (connect(info->socket, (struct sockaddr*)&info->server_infos, sizeof(info->server_infos)) < 0) {
        fprintf(stdout, "./myteams_cli: Connection failed\n");
        return (CLIENT_ERROR);
    }
    return (CLIENT_SUCCESS);
}