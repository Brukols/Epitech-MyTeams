/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** channel
*/

#ifndef CHANNEL_H_
#define CHANNEL_H_

#include "generic_list.h"
#include <uuid/uuid.h>
#include "reply_code.h"

typedef struct
{
    char name[DEFAULT_NAME_LENGTH];
    char description[DEFAULT_DESCRIPTION_LENGTH];
    uuid_t uuid;
    list_t threads;
} channel_t;

channel_t *create_channel(char *name, char *description);
void delete_channel(void *data);

#endif /* !CHANNEL_H_ */
