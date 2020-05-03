/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** load_teams
*/

#include <dirent.h>
#include <stdio.h>
#include "server.h"
#include "saving_utils.h"

static team_t *load_team(list_t users, struct dirent *dp)
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
        load_channel(new_team, path_team, sub_dp->d_name);
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