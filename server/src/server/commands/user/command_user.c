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

    return (uuid_compare(user->uuid, to_compare));
}

static int send_not_found_response(client_t *client, const char *msg)
{
    if (send_header_reply(UNKNOWN_USER, strlen(msg), client) < 0)
        return (FAILURE);
    if (!smart_buffer_add_string(client->write_buf, msg))
        return (FAILURE);
    return (SUCCESS);
}

static int send_user_info(client_t *client, user_t *user)
{
    if (send_header_reply(PRINT_USER, 49, client) < 0)
        return (FAILURE);
    if (!smart_buffer_add_data(client->write_buf, user->uuid, 16))
        return (FAILURE);
    if (!smart_buffer_add_data(client->write_buf, user->username, DEFAULT_NAME_LENGTH))
        return (FAILURE);
    if (!smart_buffer_add_data(client->write_buf, &(char){(user->nb_clients != 0)}, 1))
        return (FAILURE);
    return (SUCCESS);
}

int command_user(server_t *server, client_t *client, client_request_t *req, char *data)
{
    char *uuid = data;
    user_t *user;

    if (req->message_size != 16)
        return (send_not_found_response(client, "wrong syntax"));
    user = (user_t *)(list_get_first_node_with_value(server->users, uuid, &is_user_equal)->value);
    if (!user)
        return (send_not_found_response(client, "unable to find the user"));
    return (send_user_info(client, user));
}
