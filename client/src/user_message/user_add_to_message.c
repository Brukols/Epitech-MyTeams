/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** TODO: add description
*/

#include "user_message.h"

int user_add_to_message(user_message_t *message, char *str)
{
    if (!message || !str)
        return (CLIENT_SUCCESS);
    for (size_t i = 0; i < strlen(str); i++, message->write_pos++) {
        if (message->write_pos >= USER_MESSAGE_SIZE)
            message->write_pos = 0;
        message->buff[message->write_pos] = str[i];
    }
    return (CLIENT_SUCCESS);
}