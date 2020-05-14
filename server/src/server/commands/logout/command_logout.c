/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** command_logout
*/

#include "server.h"
#include "user.h"
#include "logging_server.h"

static const char *response = "[SERVER] Goodbye ! See you soon.";

static int send_response(server_t *server, user_t *user)
{
    for (list_t clients = server->client; clients; clients = clients->next) {
        client_t *client = (client_t *)clients->value;

        if (!client->user)
            continue;
        if (send_header_reply(EVENT_LOGGED_OUT, DEFAULT_NAME_LENGTH + 16, \
client) < 0)
            return (FAILURE);
        if (!smart_buffer_add_data(client->write_buf, user->username, \
DEFAULT_NAME_LENGTH))
            return (FAILURE);
        if (!smart_buffer_add_data(client->write_buf, user->uuid, 16))
            return (FAILURE);
    }
    return (SUCCESS);
}

int command_logout(server_t *server, client_t *client, client_request_t *req, \
char *data)
{
    char uuid[37];

    client->close = true;
    if (client->user) {
        uuid_unparse(client->user->uuid, uuid);
        server_event_user_logged_out(uuid);
        send_response(server, client->user);
    }
    if (send_header_reply(200, strlen(response), client) < 0)
        return (FAILURE);
    if (!smart_buffer_add_string(client->write_buf, response))
        return (FAILURE);
    (void)server;
    (void)req;
    (void)data;
    return (SUCCESS);
}
