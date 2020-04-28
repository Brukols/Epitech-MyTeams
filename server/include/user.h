/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** user
*/

#ifndef USER_H_
#define USER_H_

#include <uuid/uuid.h>
#include "generic_list.h"

typedef struct
{
    char *username;
    uuid_t uuid;
    list_t client;
    list_t messages;
} user_t;

#endif /* !USER_H_ */
