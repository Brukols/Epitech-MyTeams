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
    char description[DEFAULT_DESCRIPTION_LENGTH];
    uuid_t uuid;
    list_t channels;
    list_t subscribers;
} team_t;

team_t *create_team(char *name, char *description);
void delete_team(void *data);

#endif /* !TEAM_H_ */
