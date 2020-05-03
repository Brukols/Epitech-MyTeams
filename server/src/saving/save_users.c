/*
** EPITECH PROJECT, 2020
** my teams
** File description:
** save users
*/

#include "saving_utils.h"
#include <stdio.h>
#include "message.h"
#include <errno.h>

static bool save_user_meta(void *item, int fd)
{
    user_t *user = item;
    char buffer[53];
    unsigned int size = list_get_size(user->messages);

    buffer[0] = META_USER;
    memcpy(buffer + 1, user->uuid, 16);
    memcpy(buffer + 17, user->username, 32);
    memcpy(buffer + 49, &size, 4);
    return (write_buffer(fd, buffer, sizeof(buffer)));
}

static bool save_user_data(void *item, int fd)
{
    user_t *user = item;
    char type = DATA_USER;
    char buffer[536];
    message_t *msg;

    if (write(fd, &type, 1) != 1)
        return (false);
    for (list_t messages = user->messages; messages; messages=messages->next) {
        msg = messages->value;
        memcpy(buffer, msg->user_uuid, 16);
        memcpy(buffer + 16, &msg->time, 8);
        memcpy(buffer + 24, msg->message, 512);
        if (!write_buffer(fd, buffer, sizeof(buffer)))
            return (false);
    }
    return (true);
}

bool save_users(list_t users)
{
    user_t *user;
    char dir[128];
    char uuid[37] = {0};

    for (; users; users = users->next) {
        user = users->value;
        uuid_unparse(user->uuid, uuid);
        strcpy(dir, ".save/users/");
        strcat(dir, uuid);
        strcat(dir, "/");
        if (!check_and_create_directory(dir) ||
            !save_single_item(user, dir, save_user_meta, save_user_data))
            printf("Could not save user %s\n", uuid);
    }
    return (true);
}
