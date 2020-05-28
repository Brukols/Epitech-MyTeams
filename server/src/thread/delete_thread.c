/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** delete_thread
*/

#include "thread.h"

void delete_thread(void *data)
{
    thread_t *thread = data;

    if (thread->replies)
        list_clear(&thread->replies, &delete_reply);
    free(thread);
}