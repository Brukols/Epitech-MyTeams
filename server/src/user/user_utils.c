/*
** EPITECH PROJECT, 2020
** my teams
** File description:
** user utils
*/

#include "user.h"

user_t *user_get_by_uuid(list_t users, uuid_t uuid)
{
    for (; users; users = users->next) {
        user_t *user = users->value;

        if (!uuid_compare(user->uuid, uuid))
            return (user);
    }
    return (NULL);
}
