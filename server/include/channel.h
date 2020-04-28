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

typedef struct
{
    char *name;
    char *description;
    uuid_t uuid;
    list_t threads;
} channel_t;

#endif /* !CHANNEL_H_ */