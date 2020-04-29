/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** TODO: add description
*/

#include "my_teams.h"
#include "server.h"

int my_teams(int ac, char **av)
{
    server_t *server;

    if (teams_check_arg(ac, av) == TEAMS_ERROR)
        return (display_help());
    server = init_server(av);
    if (!server)
        return (TEAMS_ERROR);
    if (launch_server(server) == FAILURE)
        return (TEAMS_ERROR);
    return (TEAMS_SUCCESS);
}