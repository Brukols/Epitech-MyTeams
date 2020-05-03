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
    {PRINT_TEAM, &reply_210},
    {PRINT_CHANNEL, &reply_211},
    {PRINT_THREAD, &reply_212},
    {PRINT_PRIVATE_MESSAGES, &reply_220},
    {PRINT_TEAMS, &reply_230},
    {PRINT_CHANNELS, &reply_231},
    {PRINT_THREADS, &reply_232},
    {PRINT_REPLIES, &reply_233},
    {PRINT_SUBSCRIBED, &reply_240},
    {PRINT_UNSUBSCRIBED, &reply_241},
    {PRINT_TEAM_CREATED, &reply_250},
    {PRINT_CHANNEL_CREATED, &reply_251},
    {PRINT_THREAD_CREATED, &reply_252},
    {PRINT_REPLY_CREATED, &reply_253},
    {EVENT_TEAM_CREATED, &reply_311},
    {EVENT_CHANNEL_CREATED, &reply_312},
    {EVENT_THREAD_CREATED, &reply_313},
    {EVENT_THREAD_MESSAGE_RECEIVED, &reply_320},
    {EVENT_PRIVATE_MESSAGE_RECEIVED, &reply_321},
    {EVENT_LOGGED_IN, &reply_330},
    {EVENT_LOGGED_OUT, &reply_331},
    {SYNTAX_ERROR, &reply_500},
    {SYNTAX_ERROR_ARGS, &reply_501},
    {NOT_IMPLEMENTED, &reply_502},
    {BAD_SEQUENCE, &reply_503},
    {NOT_IMPLEMENTED_ARG, &reply_504},
    {NOT_LOGGED_IN, &reply_530},
    {CLIENT_ALREADY_EXISTS, &reply_540},
    {UNKNOWN_COMMAND, &reply_550},
    {UNKNOWN_TEAM, &reply_551},
    {UNKNOWN_CHANNEL, &reply_552},
    {UNKNOWN_THREAD, &reply_553},
    {UNKNOWN_USER, &reply_554},
    {UNAUTHORIZED, &reply_560},
    {0, NULL},
};

#endif //NWP_MYTEAMS_2019_MYTEAMS_REPLY_H
