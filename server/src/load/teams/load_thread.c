/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** TODO: add description
*/

#include <dirent.h>
#include <stdio.h>
#include <fcntl.h>
#include "file_types.h"
#include "server.h"

static thread_t *load_thread_meta(list_t users, char *path)
{
    int fd = -1;
    char type;
    uuid_t uuid;
    uuid_t user_uuid;
    char name[32] = {0};
    char message[512] = {0};
    time_t time;
    thread_t *thread = NULL;
    user_t *user = NULL;
    if ((fd = open(path, O_RDONLY)) == -1) return (NULL);
    if (read(fd, &type, 1) != 1 || read(fd, &uuid, 16) != 16
    || read(fd, &user_uuid, 16) != 16 || read(fd, &name, 32) != 32
    || read(fd, &message, 512) != 512 || read(fd, &time, 8) != 8
    || type != META_THREAD || ((user = user_get_by_uuid(users, user_uuid)) ==
    NULL)) {
        close(fd);
        return (NULL);
    }
    close(fd);
    if ((thread = create_thread(name, message, user)) == NULL) return (NULL);
    uuid_copy(thread->uuid, uuid);
    return (thread);
}

static void load_thread_data(list_t users, thread_t *thread, char *path)
{
    int fd = -1;
    char type;
    uuid_t uuid;
    time_t time;
    char message[512] = {0};
    reply_t *reply = NULL;
    if ((fd = open(path, O_RDONLY)) == -1) return;
    if (read(fd, &type, 1) != 1 || type != DATA_THREAD) {
        close(fd);
        return;
    }
    while (read(fd, &uuid, 16) == 16 && read(fd, &time, 8) == 8
    && read(fd, &message, 512) == 512) {
        if ((reply = create_reply(message)) == NULL) continue;
        if ((reply->user = user_get_by_uuid(users, uuid)) == NULL) {
            free(reply);
            continue;
        }
        reply->time = time;
        list_add_elem_at_back(&thread->replies, reply);
    }
    close(fd);
}

void load_thread(list_t users, channel_t *channel, char *path, char *thread_name)
{
    char meta_file[PATH_MAX] = {0};
    char data_file[PATH_MAX] = {0};
    thread_t *new_thread = NULL;

    if (snprintf(meta_file, PATH_MAX, "%s%s/%s", path, thread_name, ".meta")
    >= PATH_MAX)
        return;
    if (snprintf(data_file, PATH_MAX, "%s%s/%s", path, thread_name, ".data")
    >= PATH_MAX)
        return;
    if ((new_thread = load_thread_meta(users, meta_file)) == NULL)
        return;
    load_thread_data(users, new_thread, data_file);
    list_add_elem_at_back(&channel->threads, new_thread);
}