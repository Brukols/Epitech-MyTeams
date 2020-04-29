/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** write_data_client
*/

#include "client.h"
#include <unistd.h>
#include "server.h"
#include <string.h>

int write_data_client(client_t *client)
{
    ssize_t len = smart_buffer_write(client->write_buf, client->fd);

    return (len);
}