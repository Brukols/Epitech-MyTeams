/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** load_users
*/

#include "server.h"
#include "dirent.h"
#include "message.h"
#include "file_types.h"
#include <fcntl.h>
#include <stdio.h>

static void add_string(char *dest, char *name, char *name2, int path_size)
{
    memset(dest, 0, path_size);
    strcat(dest, ".save/users/");
    strcat(dest, name);
    strcat(dest, name2);
}

static int read_meta(char *path, user_t *user, int *nb_messages)
{
    char type;
    int fd = open(path, O_RDONLY);

    if (fd == -1)
        return (FAILURE);
    if (read(fd, &type, 1) < 1)
        return (FAILURE);
    if (type != META_USER)
        return (FAILURE);
    if (read(fd, user->uuid, 16) < 16)
        return (FAILURE);
    if (read(fd, user->username, 32) < 32)
        return (FAILURE);
    if (read(fd, nb_messages, sizeof(int)) < (ssize_t)sizeof(int))
        return (FAILURE);
    close(fd);
    return (SUCCESS);
}

static int load_user(server_t *server, char *name)
{
    int path_size = strlen(name) + strlen(".save/users/") + strlen("/.meta");
    char path_file[path_size];
    int nb_messages;
    user_t *user = malloc(sizeof(user_t));

    if (!user)
        return (SUCCESS);
    memset(user->username, 0, DEFAULT_NAME_LENGTH);
    user->nb_clients = 0;
    add_string(path_file, name, "/.meta", path_size);
    if (read_meta(path_file, user, &nb_messages) == FAILURE)
        return (SUCCESS);
    add_string(path_file, name, "/.data", path_size);
    if (read_data(path_file, user, nb_messages) == FAILURE)
        return (SUCCESS);
    if (!list_add_elem_at_back(&server->users, user))
        return (SUCCESS);
    return (SUCCESS);
}

int load_users(server_t *server)
{
    fprintf(stdout, "[SERVER] Loading Users...\n");
    DIR *folder = opendir(".save/users");
    struct dirent *entry;

    if (!folder) {
        printf("Unable to read users\n");
        return (SUCCESS);
    }
    server->users = NULL;
    while ((entry = readdir(folder))) {
        if (entry->d_name[0] == '.')
            continue;
        load_user(server, entry->d_name);
    }
    closedir(folder);
    fprintf(stdout, "[SERVER] Users succesfully loading...\n");
    return (SUCCESS);
}