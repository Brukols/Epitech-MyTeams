/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** load_teams
*/

#include <dirent.h>
#include <stdio.h>
#include <fcntl.h>
#include "file_types.h"
#include "server.h"

void load_team_subscriptions(list_t users, team_t *new_team, char *path)
{
    int fd = -1;
    char type;
    uuid_t uuid;
    user_t *user = NULL;

    if ((fd = open(path, O_RDONLY)) == -1) return;
    if (read(fd, &type, 1) != 1 || type != META_TEAM) {
        close(fd);
        return;
    }
    while (read(fd, &uuid, 16) == 16) {
        user = user_get_by_uuid(users, uuid);
        if (user == NULL)
            continue;
        list_add_elem_at_back(&new_team->subscribers, user);
    }
    close(fd);
}

team_t *load_team_metadata(char *path)
{
    int fd = -1;
    team_t *new_team = NULL;
    char type;
    uuid_t uuid;
    char name[32] = {0};
    char description[255] = {0};

    if ((fd = open(path, O_RDONLY)) == -1) return (NULL);
    if (read(fd, &type, 1) != 1 || read(fd, &uuid, 16) != 16
    || read(fd, &name, 32) != 32 || read(fd, &description, 255) != 255) {
        close(fd);
        return (NULL);
    }
    close(fd);
    if (type != META_TEAM || (new_team = create_team(name, description)) ==
    NULL) return (NULL);
    uuid_copy(new_team->uuid, uuid);
    return (new_team);
}

team_t *load_team_data(list_t users, char *path_team)
{
    team_t *new_team = NULL;
    char meta_file[PATH_MAX] = {0};
    char data_file[PATH_MAX] = {0};
    if (snprintf(meta_file, PATH_MAX, "%s%s", path_team, "/.meta") >= PATH_MAX)
        return (NULL);
    if (snprintf(data_file, PATH_MAX, "%s%s", path_team, "/.data") >= PATH_MAX)
        return (NULL);
    if ((new_team = load_team_metadata(meta_file)) == NULL)
        return (NULL);
    load_team_subscriptions(users, new_team, data_file);
    return (new_team);
}

team_t *load_team(list_t users, struct dirent *dp)
{
    team_t *new_team = NULL;
    char path_team[PATH_MAX] = {0};
    struct dirent *sub_dp;
    DIR *dfd;

    if (snprintf(path_team, PATH_MAX, "%s%s", "./.save/teams/", dp->d_name)
    >= PATH_MAX)
        return (NULL);
    if ((new_team = load_team_data(users, path_team)) == NULL)
        return (NULL);
    if ((dfd = opendir(path_team)) == NULL)
        return (NULL);
    while ((sub_dp = readdir(dfd)) != NULL) {
        if (sub_dp->d_type != DT_DIR || strcmp(sub_dp->d_name, ".") == 0
            || strcmp(sub_dp->d_name, "..") == 0)
            continue;
        //load_channel(new_team, path_team, sub_dp);
    }
    closedir(dfd);
    return (new_team);
}

int load_teams(server_t *server)
{
    server->teams = NULL;
    team_t *new_team = NULL;
    char *teams_save_path = "./.save/teams";
    struct dirent *dp;
    DIR *dfd;

    if ((dfd = opendir(teams_save_path)) == NULL)
        return (SUCCESS);
    while ((dp = readdir(dfd)) != NULL) {
        if (dp->d_type != DT_DIR || strcmp(dp->d_name, ".") == 0
        || strcmp(dp->d_name, "..") == 0)
            continue;
        new_team = load_team(server->users, dp);
        if (new_team != NULL) {
            list_add_elem_at_back(&server->teams, new_team);
            new_team = NULL;
        }
    }
    closedir(dfd);
    return (SUCCESS);
}