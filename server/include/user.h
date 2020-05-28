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
#include "reply_code.h"

typedef struct
{
    char username[DEFAULT_NAME_LENGTH];
    uuid_t uuid;
    int nb_clients;
    list_t messages;
} user_t;

user_t *create_user(char *username);
void delete_user(void *data);
user_t *user_get_by_uuid(list_t users, uuid_t uuid);

#endif /* !USER_H_ */
