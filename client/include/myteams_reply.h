/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** TODO: add description
*/

#ifndef NWP_MYTEAMS_2019_MYTEAMS_REPLY_H
#define NWP_MYTEAMS_2019_MYTEAMS_REPLY_H

#include "myteams_client.h"
#include "reply_code.h"

static const reply_codes_dictionnary_t replies[] =
    {
        {COMMAND_OK, &reply_200},
        {PRINT_USER, &reply_201},
        {PRINT_USERS, &reply_202},
        {EVENT_LOGGED_IN, &reply_330},
        {EVENT_LOGGED_OUT, &reply_331},
        {SYNTAX_ERROR_ARGS, &reply_501},
        {0, NULL},
    };

#endif //NWP_MYTEAMS_2019_MYTEAMS_REPLY_H
