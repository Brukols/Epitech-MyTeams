/*
** EPITECH PROJECT, 2020
** my teams
** File description:
** save channels
*/

#include "saving_utils.h"
#include "thread.h"
#include <stdio.h>

bool save_threads(list_t channels, const char *base_dir)
{
    /* channel_t *channel; */
    /* char dir[128]; */
    /* char uuid[37] = {0}; */

    /* for (; channels; channels = channels->next) { */
    /*     channel = channels->value; */
    /*     uuid_unparse(channel->uuid, uuid); */
    /*     strcpy(dir, base_dir); */
    /*     strcat(dir, uuid); */
    /*     strcat(dir, "/"); */
    /*     if (!check_and_create_directory(dir) || */
    /*         !save_single_item(channel, dir, save_channel_meta, NULL)) */
    /*         printf("Could not save channel %s\n", uuid); */
    /*     else */
    /*         save_threads(channel->threads, dir); */
    /* } */
    return (true);
}
