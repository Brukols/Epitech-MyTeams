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

typedef struct
{
    char name[DEFAULT_NAME_LENGTH];
    char description[DEFAULT_NAME_LENGTH];
    uuid_t uuid;
    time_t time;
    list_t replies;
} thread_t;

#endif /* !THREAD_H_ */
