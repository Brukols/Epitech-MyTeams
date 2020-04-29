/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** terminate
*/

#include <stdbool.h>

bool terminate(bool value)
{
    static bool term = false;

    if (value == false)
        return (term);
    term = value;
    return (term);
}