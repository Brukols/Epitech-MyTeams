/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client
*/

#ifndef MESSAGE_T_H_
#define MESSAGE_T_H_

/**************************************
** INCLUDE DEFINITION
**************************************/

#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>

/**************************************
** DEFINE DEFINITION
**************************************/

#define TCP_MSGBUFF_SIZE 10000
#define TCP_READ_SIZE 100
#define CLIENT_ERROR 84
#define CLIENT_SUCCESS 0

/**************************************
** STRUCTURE DEFINITION
**************************************/

typedef struct message_s
{
    char buff[TCP_MSGBUFF_SIZE + 1];
    int write_pos;
    int read_pos;
} message_t;

/**************************************
** FUNCTIONS DEFINITION
**************************************/

message_t *tcp_new_message(void);
int tcp_add_to_message(message_t *message, char *str);
int tcp_send_message(int socket, message_t *message);
bool tcp_is_waiting_message(message_t *message);
int tcp_receive_message(int socket, message_t *receive);
char *tcp_get_message2(char *line, char *buffer, int i, int j);
char *tcp_get_message(int socket);
char *tcp_getline_receive(message_t *receive);

#endif