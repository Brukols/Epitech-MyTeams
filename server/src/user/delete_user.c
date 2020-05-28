/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** delete_user
*/

#include "user.h"
#include "message.h"

void delete_user(void *data)
{
    user_t *user = data;

    if (user->messages)
        list_clear(&user->messages, &delete_message);
    free(user);
}