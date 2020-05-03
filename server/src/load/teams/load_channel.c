/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** TODO: add description
*/

#include <dirent.h>
#include <stdio.h>
#include <fcntl.h>
#include "server.h"
#include "saving_utils.h"

channel_t *load_channel_data(char *path)
{
    int fd = -1;
    char type;
    uuid_t  uuid;
    char name[32] = {0};
    char description[255] = {0};
    channel_t *new_channel = NULL;

    if ((fd = open(path, O_RDONLY)) == -1)
        return (NULL);
    if (read(fd, &type, 1) != 1 || read(fd, &uuid, 16) != 16
        || read(fd, &name, 32) != 32 || read(fd, &description, 255) != 255) {
        close(fd);
        return (NULL);
    }
    if ((create_channel(name, description)) == NULL) return (false);
    uuid_copy(new_channel->uuid, uuid);
    close(fd);
    return (new_channel);
}

void load_channel(team_t *new_team, char *path, char *name_chan)
{
    char meta_file[PATH_MAX] = {0};
    char channel_path[PATH_MAX] = {0};
    struct dirent *sub_dp;
    DIR *dfd;
    channel_t *new_channel = NULL;
    if (snprintf(meta_file, PATH_MAX, "%s/%s/.meta", path, name_chan)
        >= PATH_MAX || snprintf(channel_path, PATH_MAX, "%s/%s/", path,
            name_chan) >= PATH_MAX)
        return;
    if ((new_channel = load_channel_data(meta_file)) == NULL) return;
    list_add_elem_at_back(&new_team->channels, new_channel);
    if ((dfd = opendir(channel_path)) == NULL)
        return;
    while ((sub_dp = readdir(dfd)) != NULL) {
        if (sub_dp->d_type != DT_DIR || strcmp(sub_dp->d_name, ".") == 0
            || strcmp(sub_dp->d_name, "..") == 0)
            continue;
        load_thread(new_channel, channel_path, sub_dp->d_name);
    }
    closedir(dfd);
}