/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** TODO: add description
*/

#include "message_t.h"

char *tcp_getline_receive(message_t *receive)
{
    char buff[TCP_MSGBUFF_SIZE];
    int i = 0;
    int j = 0;

    bzero(&buff, TCP_MSGBUFF_SIZE);
    for (i = receive->read_pos, j = 0; i != receive->write_pos; i++, j++) {
        if (i >= TCP_MSGBUFF_SIZE) {
            i = -1;
            j--;
            continue;
        }
        buff[j] = receive->buff[i];
        if (buff[j] == '\n')
            break;
    }
    if (i == receive->write_pos) return (NULL);
    bzero(&receive->buff[receive->read_pos], j);
    receive->read_pos = i;
    return (strdup(buff));
}

int tcp_receive_message(int socket, message_t *receive)
{
    int read_nb = 0;
    char buff[TCP_READ_SIZE + 1];

    bzero(&buff, TCP_READ_SIZE + 1);
    if ((read_nb = read(socket, buff, TCP_READ_SIZE)) == 0)
        return (CLIENT_ERROR);
    for (size_t i = 0; i < strlen(buff); i++, receive->write_pos++) {
        if (receive->write_pos >= TCP_MSGBUFF_SIZE)
            receive->write_pos = 0;
        receive->buff[receive->write_pos] = buff[i];
    }
    return (CLIENT_SUCCESS);
}