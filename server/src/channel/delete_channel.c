/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** delete_channel
*/

#include "channel.h"
#include "thread.h"

void delete_channel(void *data)
{
    channel_t *channel = data;

    if (channel->threads)
        list_clear(&channel->threads, &delete_thread);
    free(channel);
}