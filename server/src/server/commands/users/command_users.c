/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** command_users
*/

#include "server.h"
#include "user.h"

int command_users(server_t *server, client_t *client, client_request_t *req, \
char *data)
{
    for (list_t users = server->users; users; users = users->next) {
        user_t *user = (user_t *)users->value;

        if (send_header_reply(PRINT_USERS, 16 + DEFAULT_NAME_LENGTH + 1, \
client) < 0)
            return (FAILURE);
        if (!smart_buffer_add_data(client->write_buf, user->uuid, 16))
            return (FAILURE);
        if (!smart_buffer_add_data(client->write_buf, user->username, \
DEFAULT_NAME_LENGTH))
            return (FAILURE);
        if (!smart_buffer_add_data(client->write_buf, \
&(char){user->nb_clients != 0}, 1))
            return (FAILURE);
    }
    (void)req;
    (void)data;
    return (SUCCESS);
}
