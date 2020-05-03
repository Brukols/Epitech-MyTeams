/*
** EPITECH PROJECT, 2020
** my teams
** File description:
** save server data
*/

#include "saving_utils.h"

bool save_server(const server_t *server)
{
    smart_buffer_t *buffer = smart_buffer_create();

    if (!buffer)
        return (false);
    if (!prepare_saving_directory())
        return (false);
    if (!save_teams(server->teams, buffer))
        return (false);
    if (!save_users(server->users, buffer))
        return (false);
    smart_buffer_destroy(buffer);
    return (true);
}
