/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** delete_team
*/

#include "team.h"
#include "channel.h"

void delete_team(void *data)
{
    team_t *team = data;

    if (team->channels)
        list_clear(&team->channels, &delete_channel);
    free(team);
}