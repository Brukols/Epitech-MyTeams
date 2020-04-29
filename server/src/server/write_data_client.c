/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** write_data_client
*/

#include "client.h"
#include <unistd.h>
#include "my_teams.h"
#include <string.h>

int write_data_client(client_t *client)
{
    ssize_t len = write(client->fd, client->write_buf, \
strlen(client->write_buf));

    if (len < 0)
        return (FAILURE);
    client->write_buf = erase_buffer(client->write_buf, len);
    if (!client->write_buf)
        return (FAILURE);
    return (0);
}