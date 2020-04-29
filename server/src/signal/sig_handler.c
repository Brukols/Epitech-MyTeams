/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** sig_handler
*/

#include <signal.h>
#include <stdbool.h>
#include "my_teams.h"

void sig_handler(int signo)
{
    if (signo == SIGINT) {
        terminate(true);
    }
}