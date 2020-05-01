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
#include "reply_code.h"

typedef struct
{
    uuid_t user_uuid;
    time_t time;
    char message[DEFAULT_BODY_LENGTH];
} message_t;

#endif /* !MESSAGE_H_ */
