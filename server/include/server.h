/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server
*/

#ifndef SERVER_H_
#define SERVER_H_

#include <netinet/ip.h>
#include "generic_list.h"
#include <uuid/uuid.h>

typedef struct
{
    int fd;
    int port;
    struct sockaddr_in addr;
    list_t users;
    list_t teams;
    list_t client;
} server_t;

server_t *init_server(char **av);
int launch_server(server_t *server);

#endif /* !SERVER_H_ */
