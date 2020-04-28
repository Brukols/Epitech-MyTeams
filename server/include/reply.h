/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** reply
*/

#ifndef REPLY_H_
#define REPLY_H_

#include <uuid/uuid.h>

typedef struct
{
    char *message;
    time_t time;
    uuid_t user_uuid;
} reply_t;

#endif /* !REPLY_H_ */
