/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server
*/

#ifndef SERVER_H_
#define SERVER_H_

#include <netinet/ip.h>
#include <uuid/uuid.h>

#include "generic_list.h"
#include "client.h"

#define TEAMS_ERROR 84
#define TEAMS_SUCCESS 0
#define FAILURE -1
#define SUCCESS 0

typedef struct __attribute__((packed))
{
    unsigned short reply;
    int message_size;
} server_reply_t;

typedef struct __attribute__((packed))
{
    unsigned char command;
    int message_size;
} client_request_t;

typedef struct
{
    int fd;
    int port;
    struct sockaddr_in addr;
    list_t users;
    list_t teams;
    list_t client;
} server_t;

int my_teams_server(int ac, char **av);

/* HELP */
int display_help(void);
int teams_check_arg(int ac, char **av);

/* SIGNAL */
bool terminate(bool value);
void sig_handler(int signo);

/* SERVER */
server_t *init_server(char **av);
void delete_server(server_t *server);
int launch_server(server_t *server);
int translate_select(server_t *server, fd_set *readfs, fd_set *writefs);
int new_connection(server_t *server);
int read_data_client(server_t *server, client_t *client);
int write_data_client(client_t *client);

/* BUFFER */
void *concat_buffer(void *dest, const void *src);
char *erase_buffer(char *buffer, long pos);

#endif /* !SERVER_H_ */
