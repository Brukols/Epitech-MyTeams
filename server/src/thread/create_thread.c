/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** create_thread
*/

#include "server.h"

thread_t *create_thread(char *title, char *message)
{
    thread_t *thread = malloc(sizeof(thread_t));

    if (!thread)
        return (NULL);
    memset(thread->title, 0, DEFAULT_NAME_LENGTH);
    memset(thread->message, 0, DEFAULT_BODY_LENGTH);
    strcpy(thread->title, title);
    strcpy(thread->message, message);
    uuid_generate(thread->uuid);
    thread->user = NULL;
    thread->replies = NULL;
    thread->time = time(NULL);
    return (thread);
}