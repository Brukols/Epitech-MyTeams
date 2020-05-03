/*
** EPITECH PROJECT, 2020
** my teams
** File description:
** save teams
*/

#include "saving_utils.h"
#include <stdio.h>

static bool save_team_meta(void *item, int fd)
{
    team_t *team = item;
    char buffer[53];
    unsigned int size = list_get_size(team->subscribers);

    buffer[0] = META_USER;
    memcpy(buffer + 1, team->uuid, 16);
    memcpy(buffer + 17, team->name, 32);
    memcpy(buffer + 49, &size, 4);
    return (write_buffer(fd, buffer, sizeof(buffer)));
}

static bool save_team_data(void *item, int fd)
{
    user_t *user = item;
    char type = DATA_USER;
    char buffer[16];

    if (write(fd, &type, 1) != 1)
        return (false);
    for (list_t messages = user->messages; messages; messages=messages->next) {
        /* msg = messages->value; */
        /* memcpy(buffer, msg->user_uuid, 16); */
        /* memcpy(buffer + 16, &msg->time, 8); */
        /* memcpy(buffer + 24, msg->message, 512); */
        if (!write_buffer(fd, buffer, sizeof(buffer)))
            return (false);
    }
    return (true);
}

bool save_teams(list_t teams)
{
    /* team_t *team; */
    /* char dir[128]; */
    /* char uuid[37] = {0}; */

    /* for (; teams; teams = teams->next) { */
    /*     team = teams->value; */
    /*     uuid_unparse(team->uuid, uuid); */
    /*     strcpy(dir, ".save/teams/"); */
    /*     strcat(dir, uuid); */
    /*     strcat(dir, "/"); */
    /*     if (!check_and_create_directory(dir) || */
    /*         !save_single_item(team, dir, save_team_meta, save_team_data)) */
    /*         printf("Could not save team %s\n", uuid); */
    /*     else */
    /*         save_channels(team->channels, dir); */
    /* } */
    return (true);
}