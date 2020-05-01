/*
** EPITECH PROJECT, 2020
** my teams
** File description:
** utils
*/

#include "client.h"

bool client_is_logged_in(const client_t *client)
{
    return (client->user != NULL);
}
