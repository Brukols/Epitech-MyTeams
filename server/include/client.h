/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** TODO: add description
*/

#ifndef NWP_MYTEAMS_2019_CLIENT_H
#define NWP_MYTEAMS_2019_CLIENT_H

#include <stdbool.h>
#include "smart_buffer.h"
#include "user.h"

/**************************************
** STRUCT
**************************************/

typedef struct
{
    int fd;
    bool close;
    smart_buffer_t *write_buf;
    smart_buffer_t *read_buf;
    char *path;
    user_t *user;
} client_t;

client_t *create_client(int fd);
void delete_client(void *data);

bool client_is_logged_in(const client_t *client);

#endif //NWP_MYTEAMS_2019_CLIENT_H
