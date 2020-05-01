/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** command_user
*/

#include "server.h"
#include "user.h"

static int is_user_equal(void *value, void *to_compare)
{
    user_t *user = (user_t *)value;
    char *uuid = to_compare;

    return (strncmp((char *)(user->uuid), uuid, 16));
}

static int send_not_found_response(client_t *client, const char *msg)
{
    if (send_header_reply(501, strlen(msg), client) < 0)
        return (FAILURE);
    if (!smart_buffer_add_string(client->write_buf, msg))
        return (FAILURE);
    return (SUCCESS);
}

static int send_user_info(client_t *client, user_t *user)
{
    if (send_header_reply(501, 49, client) < 0)
        return (FAILURE);
    if (!smart_buffer_add_data(client->write_buf, user->uuid, 16))
        return (FAILURE);
    if (!smart_buffer_add_data(client->write_buf, user->username, 32))
        return (FAILURE);
    if (!smart_buffer_add_data(client->write_buf, &(char){user->status}, 1))
        return (FAILURE);
    return (SUCCESS);
}

int command_user(server_t *server, client_t *client, client_request_t *req, char *data)
{
    char *uuid = data;
    user_t *user;

    if (req->message_size != 16)
        return (send_not_found_response(client, "wrong syntax"));
    user = (user_t *)list_get_first_node_with_value(server->users, uuid, &is_user_equal);
    if (!user)
        return (send_not_found_response(client, "unable to found the user"));
    return (send_user_info(client, user));
}