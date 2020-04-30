/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** TODO: add description
*/

#include "myteams_client.h"

static const commands_dictionnary_t commands[] =
{
    {"/help", &help_cmd},
    {"/login", &login_cmd},
    {"/logout", &logout_cmd},
    {"/users", &users_cmd},
    {"/user", &user_cmd},
    {"/send", &send_cmd},
    {"/messages", &messages_cmd},
    {"/subscribe", &subscribe_cmd},
    {"/subscribed", &subscribed_cmd},
    {"/unsubscribe", &unsubscribe_cmd},
    {"/use", &use_cmd},
    {"/create", &create_cmd},
    {"/list", &list_cmd},
    {"/info", &info_cmd},
    {"UNKNOWN", NULL},
};