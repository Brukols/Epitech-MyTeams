/*
** EPITECH PROJECT, 2020
** my teams
** File description:
** save channels
*/

#include "saving_utils.h"
#include "channel.h"
#include <stdio.h>

static bool save_channel_meta(void *item, int fd)
{
    channel_t *channel = item;
    char buffer[304];

    buffer[0] = META_TEAM;
    memcpy(buffer + 1, channel->uuid, 16);
    memcpy(buffer + 17, channel->name, 32);
    memcpy(buffer + 49, channel->description, 255);
    return (write_buffer(fd, buffer, sizeof(buffer)));
}

bool save_channels(list_t channels, const char *base_dir)
{
    channel_t *channel;
    char dir[128];
    char uuid[37] = {0};

    for (; channels; channels = channels->next) {
        channel = channels->value;
        uuid_unparse(channel->uuid, uuid);
        strcpy(dir, base_dir);
        strcat(dir, uuid);
        strcat(dir, "/");
        if (!check_and_create_directory(dir) ||
            !save_single_item(channel, dir, save_channel_meta, NULL))
            printf("Could not save channel %s\n", uuid);
        else
            save_threads(channel->threads, dir);
    }
    return (true);
}
