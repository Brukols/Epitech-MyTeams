/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** TODO: add description
*/

#ifndef NWP_MYTEAMS_2019_MYTEAMS_REPLY_H
#define NWP_MYTEAMS_2019_MYTEAMS_REPLY_H

#include "myteams_client.h"

static const reply_codes_dictionnary_t replies[] =
    {
        {200, &reply_200},
        {300, &reply_300},
        {0, NULL},
    };

#endif //NWP_MYTEAMS_2019_MYTEAMS_REPLY_H
