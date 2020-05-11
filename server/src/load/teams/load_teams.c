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
        if (ignore_directory(sub_dp)) continue;
        load_channel(users, new_team, path_team, sub_dp->d_name);
    }
    closedir(dfd);
    return (new_team);
}

int load_teams(server_t *server)
{
    fprintf(stdout, "[SERVER] Loading Teams, Channels and Threads...\n");
    server->teams = NULL;
    team_t *new_team = NULL;
    char *teams_save_path = "./.save/teams";
    struct dirent *dp;
    DIR *dfd;

    if ((dfd = opendir(teams_save_path)) == NULL) return (SUCCESS);
    while ((dp = readdir(dfd)) != NULL) {
        if (ignore_directory(dp)) continue;
        new_team = load_team(server->users, dp);
        if (new_team != NULL) {
            list_add_elem_at_back(&server->teams, new_team);
            new_team = NULL;
            printf("[SERVER] Teams %s successfully loading...\n\n", dp->d_name);
        }
    }
    closedir(dfd);
    printf("[SERVER] Teams, Channels and Threads successfully loading...\n");
    return (SUCCESS);
}