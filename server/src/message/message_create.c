/*
** EPITECH PROJECT, 2020
** my teams
** File description:
** message create
*/

#include "message.h"
#include <string.h>

message_t *message_create(const char *msg, const uuid_t from, time_t time)
{
    message_t *message = malloc(sizeof(message_t));

    if (message) {
        memcpy(message->message, msg, sizeof(message->message));
        memcpy(message->user_uuid, from, sizeof(uuid_t));
        message->time = time;
    }
    return (message);
}
