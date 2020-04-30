/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** create_user
*/

#include "user.h"
#include <uuid/uuid.h>
#include <string.h>

user_t *create_user(char *username)
{
    user_t *user = malloc(sizeof(user_t));

    if (!user)
        return (NULL);
    user->username = strdup(username);
    user->messages = NULL;
    user->client = NULL;
    uuid_generate(user->uuid);
    return (user);
}