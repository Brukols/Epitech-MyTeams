/*
** EPITECH PROJECT, 2020
** my teams
** File description:
** save users
*/

#include "saving_utils.h"
#include <stdio.h>

static bool save_single_user_meta(user_t *user, smart_buffer_t *buff, int fd)
{
    
}

static bool save_single_user_data(user_t *user, smart_buffer_t *buff, int fd)
{
    
}

static bool save_single_user(user_t *usr, const char *dir, smart_buffer_t *buff)
{
    int metafd = get_meta_fd(dir);
    int datafd = get_data_fd(dir);

    if (metafd == -1 || datafd == -1) {
        metafd != -1 ? close(metafd) : 0;
        datafd != -1 ? close(datafd) : 0;
        return (false);
    }
    if (save_single_user_meta(usr, buff, metafd))
        return (false);
    if (save_single_user_data(usr, buff, metafd))
        return (false);
    return (true);
}

bool save_users(list_t users, smart_buffer_t *buffer)
{
    user_t *user;
    char dir[128] = ".save/users/";
    int len = strlen(dir);

    for (; users; users = users->next) {
        user = users->value;
        uuid_unparse(user->uuid, dir + len);
        if (!check_and_create_directory(dir)) {
            printf("Could not save user %s\n", dir + len);
            continue;
        }
        strcat(dir, "/");
        if (!save_single_user(user, dir, buffer))
            return (false);
    }
    return (true);
}
