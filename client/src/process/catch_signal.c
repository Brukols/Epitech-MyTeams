/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** TODO: add description
*/

#include "myteams_client.h"

bool terminate(bool value)
{
    static bool term = false;

    if (value == false)
        return (term);
    term = value;
    return (term);
}

void sig_handler(int signo)
{
    if (signo == SIGINT) {
        terminate(true);
    }
}