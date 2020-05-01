/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** reply
*/

#ifndef REPLY_H_
#define REPLY_H_

#include <uuid/uuid.h>
#include "reply_code.h"

typedef struct
{
    char message[DEFAULT_BODY_LENGTH];
    time_t time;
    uuid_t user_uuid;
} reply_t;

#endif /* !REPLY_H_ */
