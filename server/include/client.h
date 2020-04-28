/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** TODO: add description
*/

#ifndef NWP_MYTEAMS_2019_CLIENT_H
#define NWP_MYTEAMS_2019_CLIENT_H

#include <stdbool.h>

/**************************************
** STRUCT
**************************************/

typedef struct
{
    int fd;
    bool close;
    char *write_buf;
    char *read_buf;
    char *path;
} client_t;

#endif //NWP_MYTEAMS_2019_CLIENT_H
