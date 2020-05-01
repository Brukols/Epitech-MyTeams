/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** create_user
*/

#include "user.h"
#include <uuid/uuid.h>
#include <string.h>

#include "server.h"

user_t *create_user(char *username)
{
    user_t *user = malloc(sizeof(user_t));

    if (!user)
        return (NULL);
    memset(user->username, 0, DEFAULT_NAME_LENGTH);
    strcpy(user->username, username);
    user->messages = NULL;
    user->status = 0;
    user->nb_clients = 0;
    uuid_generate(user->uuid);
    return (user);
}