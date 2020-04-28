/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** TODO: add description
*/

#include "my_teams.h"

int my_teams(int ac, char **av)
{
    if (teams_check_arg(ac, av) == TEAMS_ERROR)
        return (display_help());
    return (TEAMS_SUCCESS);
}