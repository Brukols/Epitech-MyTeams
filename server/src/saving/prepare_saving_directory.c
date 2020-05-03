/*
** EPITECH PROJECT, 2020
** my teams
** File description:
** prepare saving directory
*/

#include "saving_utils.h"

bool prepare_saving_directory(void)
{
    if (!check_and_create_directory(".save/"))
        return (false);
    if (!check_and_create_directory(".save/users/"))
        return (false);
    if (!check_and_create_directory(".save/teams/"))
        return (false);
    return (true);
}
