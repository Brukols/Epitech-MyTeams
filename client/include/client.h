/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client
*/

#ifndef CLIENT_H_
#define CLIENT_H_

/**************************************
** INCLUDE
**************************************/

#include <netinet/in.h>

/**************************************
** DEFINE
**************************************/

#define CLIENT_ERROR 84
#define CLIENT_SUCCESS 0

/**************************************
** STRUCT
**************************************/

typedef struct
{
    int socket;
    struct sockaddr_in server_infos;
} client_t;

/**************************************
** FUNCTIONS
**************************************/
int client(int ac, char **av);

/* HELP */
void display_help(char *path);
int client_check_arg(int ac, char **av);

/* INIT */
client_t *init_client();
int connect_client(client_t *info, char *ip, char *port);

/* CLEAN */
void close_client(client_t *info);

#endif /* !CLIENT_H_ */
