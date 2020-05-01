/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** command_logout
*/

#include "server.h"
#include "user.h"

const char *response = "Goodbye";

// static int broadcast_user_disconnect(server_t *server, user_t *user)
// {

// }

int command_logout(server_t *server, client_t *client, client_request_t *req, char *data)
{
    client->close = true;
    if (send_header_reply(EVENT_LOGGED_OUT, strlen(response), client) < 0)
        return (FAILURE);
    if (!smart_buffer_add_string(client->write_buf, response))
        return (FAILURE);
    // if (send_header_reply(301, DEFAULT_NAME_LENGTH + 16, client) < 0)
    //     return (FAILURE);
    // if (!smart_buffer_add_data(client->write_buf, user->username, DEFAULT_NAME_LENGTH))
    //     return (FAILURE);
    // if (!smart_buffer_add_data(client->write_buf, user->uuid, 16))
    //     return (FAILURE);
    (void)server;
    (void)req;
    (void)data;
    return (SUCCESS);
}
