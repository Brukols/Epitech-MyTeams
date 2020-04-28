/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** main
*/

#include <stdio.h>
#include <string.h>
#include "client.h"

void display_help(char *path)
{
    printf("USAGE: %s ip port\n\tip\tis the server ip address on which the \
server socket listens\n\tport\tis the port number on which the server socket \
listens\n", path);
}

int main(int ac, char **av)
{
    if ((ac == 2 && !strcmp(av[1], "-help")) || ac != 3) {
        display_help(av[0]);
        return (0);
    }
    return (client(ac, av));
}
