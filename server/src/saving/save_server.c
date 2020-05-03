/*
** EPITECH PROJECT, 2020
** my teams
** File description:
** save server data
*/

#include "saving_utils.h"

bool save_server(const server_t *server)
{
    if (!prepare_saving_directory())
        return (false);
    if (!save_users(server->users))
        return (false);
    if (!save_teams(server->teams))
        return (false);
    return (true);
}
