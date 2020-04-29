/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client
*/

#ifndef MYTEAMS_CLIENT_H_
#define MYTEAMS_CLIENT_H_

/**************************************
** INCLUDE
**************************************/

#include <netinet/in.h>
#include <stdbool.h>
#include "user_message.h"

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
    bool close;
    int socket;
    struct sockaddr_in server_infos;
    user_message_t *user_in;
    user_message_t *user_out;
    fd_set reads;
    fd_set writes;
    fd_set excepts;
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

/* PROCESS */
int run_client(client_t *info);
int select_activities(client_t *info);
int handle_io_activities(client_t *info);

/* CLIENT */
int handle_client_activities(client_t *info);

#endif /* !CLIENT_H_ */
