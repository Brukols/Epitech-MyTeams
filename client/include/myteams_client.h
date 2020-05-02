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
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include "requests.h"
#include "user_message.h"
#include "smart_buffer.h"

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
    smart_buffer_t *server_in;
    smart_buffer_t *server_out;
    fd_set reads;
    fd_set writes;
    fd_set excepts;
} client_t;

typedef struct
{
    char *name;
    int (*ft)(client_t *client, const char *cmd);
} commands_dictionnary_t;

typedef struct
{
    unsigned short code;
    int (*ft)(client_t *client, server_reply_t *header);
} reply_codes_dictionnary_t;

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
bool get_arg(const char *command, char *buf, int size, int arg_no);
int get_arg_nb(const char *command);
int get_arg_size(const char *command, int arg_no);

/* COMMANDS */
int help_cmd(client_t *info, const char *cmd);
int login_cmd(client_t *info, const char *cmd);
int logout_cmd(client_t *info, const char *cmd);
int users_cmd(client_t *info, const char *cmd);
int user_cmd(client_t *info, const char *cmd);
int send_cmd(client_t *info, const char *cmd);
int messages_cmd(client_t *info, const char *cmd);
int subscribe_cmd(client_t *info, const char *cmd);
int subscribed_cmd(client_t *info, const char *cmd);
int unsubscribe_cmd(client_t *info, const char *cmd);
int use_cmd(client_t *info, const char *cmd);
int create_cmd(client_t *info, const char *cmd);
int list_cmd(client_t *info, const char *cmd);
int info_cmd(client_t *info, const char *cmd);

/* SERVER */
int handle_server_activities(client_t *info);

/* REPLIES */
int reply_200(client_t *info, server_reply_t *header);
int reply_201(client_t *info, server_reply_t *header);
int reply_330(client_t *info, server_reply_t *header);
int reply_331(client_t *info, server_reply_t *header);
int reply_501(client_t *info, server_reply_t *header);

#endif /* !CLIENT_H_ */
