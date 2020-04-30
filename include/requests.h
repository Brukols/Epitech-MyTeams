/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** TODO: add description
*/

#ifndef NWP_MYTEAMS_2019_REQUESTS_H
#define NWP_MYTEAMS_2019_REQUESTS_H

typedef struct __attribute__((packed))
{
    unsigned short reply;
    int message_size;
} server_reply_t;

typedef struct __attribute__((packed))
{
    unsigned char command;
    int message_size;
} client_request_t;

#endif //NWP_MYTEAMS_2019_REQUESTS_H
