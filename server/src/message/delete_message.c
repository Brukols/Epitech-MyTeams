/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** delete_message
*/

#include "message.h"

void delete_message(void *data)
{
    free(data);
}