/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** TODO: add description
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "client.h"

void display_help(char *path)
{
    printf("USAGE: %s ip port\n\tip\tis the server ip address on which the \
server socket listens\n\tport\tis the port number on which the server socket \
listens\n", path);
}

int client_check_arg(int ac, char **av)
{
    if (ac != 3 || !strcmp(av[1], "-help")) {
        display_help(av[0]);
        return (CLIENT_ERROR);
    }
    for (int i = 0; av[2][i]; i++) {
        if (!isdigit(av[2][i])) {
            display_help(av[0]);
            return (CLIENT_ERROR);
        }
    }
    return (CLIENT_SUCCESS);
}