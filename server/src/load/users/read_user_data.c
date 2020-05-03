/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** read_user_data
*/

#include "server.h"
#include "message.h"
#include "file_types.h"
#include <fcntl.h>

int fill_user_messages(int fd, user_t *user, int nb_messages)
{
    user->messages = NULL;
    for (int i = 0; i < nb_messages; i++) {
        message_t *message = malloc(sizeof(message_t));

        if (!message)
            return (FAILURE);
        if (read(fd, message->user_uuid, 16) < 16)
            return (FAILURE);
        if (read(fd, &message->time, sizeof(time_t)) < (ssize_t)sizeof(time_t))
            return (FAILURE);
        if (read(fd, message->message, DEFAULT_BODY_LENGTH) < \
DEFAULT_BODY_LENGTH)
            return (FAILURE);
        if (!list_add_elem_at_back(&user->messages, message))
            return (FAILURE);
    }
    return (SUCCESS);
}

int read_data(char *path, user_t *user, int nb_messages)
{
    char type;
    int fd = open(path, O_RDONLY);

    if (fd < 0)
        return (FAILURE);
    if (read(fd, &type, 1) < 1)
        return (FAILURE);
    if (type != DATA_USER)
        return (FAILURE);
    if (fill_user_messages(fd, user, nb_messages) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}