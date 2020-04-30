/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** TODO: add description
*/

#include "myteams_client.h"

int handle_client_activities(client_t *info)
{
    char *command = NULL;
    if ((command = user_getline_receive(info->user_in)) == NULL)
        return (CLIENT_SUCCESS);
    return (CLIENT_SUCCESS);
}