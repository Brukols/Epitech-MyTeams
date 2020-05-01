/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** create_team
*/

#include "server.h"

team_t *create_team(char *name, char *description)
{
    team_t *team = malloc(sizeof(team_t));

    if (!team)
        return (NULL);
    strcpy(team->name, name);
    strcpy(team->description, description);
    team->channels = NULL;
    uuid_generate(team->uuid);
    return (team);
}