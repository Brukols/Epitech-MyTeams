/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** TODO: add description
*/

#include "user_message.h"

char *user_getline_receive(user_message_t *receive)
{
    char buff[USER_MESSAGE_SIZE];
    int i = 0;
    int j = 0;

    bzero(&buff, USER_MESSAGE_SIZE);
    for (i = receive->read_pos, j = 0; i != receive->write_pos; i++, j++) {
        if (i >= USER_MESSAGE_SIZE) {
            i = -1;
            j--;
            continue;
        }
        buff[j] = receive->buff[i];
        if (buff[j] == '\n')
            break;
    }
    if (i == receive->write_pos) return (NULL);
    bzero(&receive->buff[receive->read_pos], j + 1);
    receive->read_pos = i + 1;
    return (strdup(buff));
}

int user_receive_message(int socket, user_message_t *receive)
{
    int read_nb = 0;
    char buff[USER_MESSAGE_READ_SIZE + 1];

    bzero(&buff, USER_MESSAGE_READ_SIZE + 1);
    if ((read_nb = read(socket, buff, USER_MESSAGE_READ_SIZE)) == 0)
        return (CLIENT_ERROR);
    for (size_t i = 0; i < strlen(buff); i++, receive->write_pos++) {
        if (receive->write_pos >= USER_MESSAGE_SIZE)
            receive->write_pos = 0;
        receive->buff[receive->write_pos] = buff[i];
    }
    return (CLIENT_SUCCESS);
}