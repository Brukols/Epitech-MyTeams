/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** TODO: add description
*/

#include "user_message.h"

user_message_t *user_new_message(void)
{
    user_message_t *message = malloc(sizeof(user_message_t));

    if (!message)
        return (NULL);
    bzero(message->buff, USER_MESSAGE_SIZE + 1);
    message->write_pos = 0;
    message->read_pos = 0;
    return (message);
}