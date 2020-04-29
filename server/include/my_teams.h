/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** TODO: add description
*/

#ifndef NWP_MYTEAMS_2019_MY_TEAMS_H
#define NWP_MYTEAMS_2019_MY_TEAMS_H

/**************************************
** INCLUDE
**************************************/

/**************************************
** DEFINE
**************************************/
#define TEAMS_ERROR 84
#define TEAMS_SUCCESS 0
#define FAILURE -1
#define SUCCESS 0

#include <stdbool.h>
#include "server.h"
#include "client.h"

/**************************************
** STRUCT
**************************************/

/**************************************
** FUNCTION
**************************************/
int my_teams(int ac, char **av);

/* HELP */
int display_help();
int teams_verif_arg(int ac, char **av);

/* SIGNAL */
bool terminate(bool value);
void sig_handler(int signo);

/* SERVER */
int translate_select(server_t *server, fd_set *readfs, fd_set *writefs);
int new_connection(server_t *server);
int read_data_client(server_t *server, client_t *client);
int write_data_client(client_t *client);

/* BUFFER */
char *concat_buffer(char *dest, char *src);
char *erase_buffer(char *buffer, long pos);

#endif //NWP_MYTEAMS_2019_MY_TEAMS_H
