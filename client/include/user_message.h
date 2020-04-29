/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client
*/

#ifndef USER_MESSAGE_H_
#define USER_MESSAGE_H_

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

#define USER_MESSAGE_SIZE 10000
#define USER_MESSAGE_READ_SIZE 100
#define CLIENT_ERROR 84
#define CLIENT_SUCCESS 0

/**************************************
** STRUCTURE DEFINITION
**************************************/

typedef struct
{
    char buff[USER_MESSAGE_SIZE + 1];
    int write_pos;
    int read_pos;
} user_message_t;

/**************************************
** FUNCTIONS DEFINITION
**************************************/

user_message_t *user_new_message(void);
int user_add_to_message(user_message_t *message, char *str);
int user_send_message(int socket, user_message_t *message);
bool user_is_waiting_message(user_message_t *message);
int user_receive_message(int socket, user_message_t *receive);
char *user_get_message2(char *line, char *buffer, int i, int j);
char *user_get_message(int socket);
char *user_getline_receive(user_message_t *receive);

#endif