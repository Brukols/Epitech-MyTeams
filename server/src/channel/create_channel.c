/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** create_channel
*/

#include "server.h"

channel_t *create_channel(char *name, char *description)
{
    channel_t *channel = malloc(sizeof(channel_t));

    if (!channel)
        return (NULL);
    memset(channel->name, 0, DEFAULT_NAME_LENGTH);
    memset(channel->description, 0, DEFAULT_DESCRIPTION_LENGTH);
    strcpy(channel->name, name);
    strcpy(channel->description, description);
    channel->threads = NULL;
    uuid_generate(channel->uuid);
    return (channel);
}