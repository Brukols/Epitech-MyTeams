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
    memset(team->name, 0, DEFAULT_NAME_LENGTH);
    memset(team->description, 0, DEFAULT_DESCRIPTION_LENGTH);
    strcpy(team->name, name);
    strcpy(team->description, description);
    team->channels = NULL;
    team->subscribers = NULL;
    uuid_generate(team->uuid);
    return (team);
}