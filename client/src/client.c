/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client
*/

#include "myteams_client.h"
#include <stddef.h>

int client(int ac, char **av)
{
    client_t *info = NULL;
    if (client_check_arg(ac, av) == CLIENT_ERROR)
        return (CLIENT_SUCCESS);
    if ((info = init_client()) == NULL)
        return (CLIENT_ERROR);
    if (connect_client(info, av[1], av[2]) == CLIENT_ERROR) {
        close_client(info);
        return (CLIENT_ERROR);
    }
    if (run_client(info) == CLIENT_ERROR) {
        close_client(info);
        return (CLIENT_ERROR);
    }
    close_client(info);
    return (CLIENT_SUCCESS);
}