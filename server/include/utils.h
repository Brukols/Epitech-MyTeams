/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** utils
*/

#ifndef UTILS_H_
#define UTILS_H_

#include "reply_code.h"
#include "server.h"

typedef struct
{
    enum reply_code_e code;
    int (*fct)(server_t *, client_t *, client_request_t *, char *);
} commands_t;

#endif /* !UTILS_H_ */
