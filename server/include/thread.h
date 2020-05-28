/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** thread
*/

#ifndef THREAD_H_
#define THREAD_H_

#include "reply_code.h"
#include <time.h>
#include <uuid/uuid.h>
#include "generic_list.h"
#include "reply.h"
#include "user.h"

typedef struct
{
    char title[DEFAULT_NAME_LENGTH];
    char message[DEFAULT_BODY_LENGTH];
    uuid_t uuid;
    user_t *user;
    time_t time;
    list_t replies;
} thread_t;

thread_t *create_thread(char *title, char *message, user_t *user);
void delete_thread(void *data);

#endif /* !THREAD_H_ */
