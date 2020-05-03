/*
** EPITECH PROJECT, 2020
** my teams
** File description:
** save channels
*/

#include "saving_utils.h"
#include "thread.h"
#include <stdio.h>

static bool save_thread_data(void *item, int fd)
{
    thread_t *thread = item;
    char type = DATA_THREAD;
    char buffer[536];
    reply_t *reply = NULL;

    if (write(fd, &type, 1) != 1)
        return (false);
    for (list_t replies = thread->replies; replies; replies = replies->next) {
        reply = replies->value;
        memcpy(buffer, reply->user->uuid, 16);
        memcpy(buffer + 16, &reply->time, 8);
        memcpy(buffer + 24, &reply->message, 512);
        if (!write_buffer(fd, buffer, sizeof(buffer)))
            return (false);
    }
    return (true);
}

static bool save_thread_meta(void *item, int fd)
{
    thread_t *thread = item;
    char buffer[573];
    unsigned int size = list_get_size(thread->replies);

    buffer[0] = META_THREAD;
    memcpy(buffer + 1, thread->uuid, 16);
    memcpy(buffer + 17, thread->title, 32);
    memcpy(buffer + 49, thread->message, 512);
    memcpy(buffer + 561, &thread->time, 8);
    memcpy(buffer + 569, &size, 4);
    return (write_buffer(fd, buffer, sizeof(buffer)));
}

bool save_threads(list_t threads, const char *base_dir)
{
    thread_t *thread;
    char dir[128];
    char uuid[37] = {0};

    for (; threads; threads = threads->next) {
        thread = threads->value;
        uuid_unparse(thread->uuid, uuid);
        strcpy(dir, base_dir);
        strcat(dir, uuid);
        strcat(dir, "/");
        if (!check_and_create_directory(dir) ||
            !save_single_item(thread, dir, save_thread_meta, save_thread_data))
            printf("Could not save thread %s\n", uuid);
    }
    return (true);
}
