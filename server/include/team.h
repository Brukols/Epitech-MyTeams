/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** team
*/

#ifndef TEAM_H_
#define TEAM_H_

#include <uuid/uuid.h>
#include "generic_list.h"
#include "reply_code.h"

typedef struct
{
    char name[DEFAULT_NAME_LENGTH];
    char description[DEFAULT_NAME_LENGTH];
    uuid_t uuid;
    list_t channels;
} team_t;

#endif /* !TEAM_H_ */
