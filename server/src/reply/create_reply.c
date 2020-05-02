/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** create_reply
*/

#include "server.h"

reply_t *create_reply(char *message)
{
    reply_t *reply = malloc(sizeof(reply_t));

    if (!reply)
        return (NULL);
    memset(reply->message, 0, DEFAULT_BODY_LENGTH);
    strcpy(reply->message, message);
    reply->time = time(NULL);
    reply->user = NULL;
    return (reply);
}