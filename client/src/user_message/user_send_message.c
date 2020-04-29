/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** TODO: add description
*/

#include "user_message.h"

int user_send_message(int socket, user_message_t *message)
{
    int sending_byte = 0;

    if (message->buff[message->read_pos] == 0)
        return (CLIENT_SUCCESS);

    while ((sending_byte = write(socket, &message->buff[message->read_pos],
    strlen(&message->buff[message->read_pos]))) > 0) {

        bzero(&message->buff[message->read_pos], sending_byte);
        message->read_pos += sending_byte;
        if (message->read_pos >= USER_MESSAGE_SIZE)
            message->read_pos = 0;
        if (message->buff[message->read_pos] == 0)
            break;
    }
    if (sending_byte == -1)
        return (CLIENT_ERROR);
    return (CLIENT_SUCCESS);
}