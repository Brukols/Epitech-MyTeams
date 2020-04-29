/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** TODO: add description
*/

#include "message_t.h"

bool tcp_is_waiting_message(message_t *message)
{
    if (message->buff[message->read_pos] == 0)
        return (false);
    return (true);
}