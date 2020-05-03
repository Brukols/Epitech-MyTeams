/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** load_teams
*/

#include <dirent.h>
#include "server.h"

team_t *load_team(struct dirent *dp)
{
    team_t *new_team = NULL;

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
        if (dp->d_type != DT_DIR)
            continue;
        new_team = load_team(dp);
        if (new_team != NULL) {
            list_add_elem_at_back(&server->teams, new_team);
            new_team = NULL;
        }
    }
    closedir(dfd);
    return (SUCCESS);
}