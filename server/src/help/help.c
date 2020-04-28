/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** TODO: add description
*/

#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "my_teams.h"

int display_help()
{
    printf("USAGE: ./myteams_server port\n\n");
    printf("\tport  is the number on which the server socket listens.\n");
    return (TEAMS_SUCCESS);
}

int teams_verif_arg(int ac, char **av)
{
    if (ac != 2)
        return (TEAMS_ERROR);
    if (strcmp(av[1], "-help") == TEAMS_SUCCESS)
        return (TEAMS_ERROR);
    for (int i = 0; av[1][i]; i++) {
        if (!isdigit(av[1][i]))
            return (TEAMS_ERROR);
    }
    return (TEAMS_SUCCESS);
}