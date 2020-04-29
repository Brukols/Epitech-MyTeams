/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** TODO: add description
*/

#include "message_t.h"

int tcp_add_to_message(message_t *message, char *str)
{
    if (!message || !str)
        return (CLIENT_SUCCESS);
    for (size_t i = 0; i < strlen(str); i++, message->write_pos++) {
        if (message->write_pos >= TCP_MSGBUFF_SIZE)
            message->write_pos = 0;
        message->buff[message->write_pos] = str[i];
    }
    return (CLIENT_SUCCESS);
}