/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** user_is_in_team
*/

#include "server.h"

bool user_is_in_team(client_t *client, team_t *team)
{
    for (list_t users = team->subscribers; users; users = users->next) {
        if (users->value == client->user)
            return (true);
    }
    return (false);
}