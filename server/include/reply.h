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
#include "user.h"

typedef struct
{
    char message[DEFAULT_BODY_LENGTH];
    time_t time;
    user_t *user;
} reply_t;

reply_t *create_reply(char *message);
void delete_reply(void *data);

#endif /* !REPLY_H_ */
