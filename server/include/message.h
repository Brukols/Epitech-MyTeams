/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** message
*/

#ifndef MESSAGE_H_
#define MESSAGE_H_

#include "generic_list.h"
#include <uuid/uuid.h>

typedef struct
{
    uuid_t user_uuid;
    time_t time;
    char *message;
} message_t;

#endif /* !MESSAGE_H_ */
