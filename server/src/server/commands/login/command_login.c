/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** command_login
*/

#include "server.h"
#include "user.h"
#include "logging_server.h"

static int if_user_equal(void *user, void *username)
{
    if (!strcmp(((user_t *)user)->username, ((char *)username)))
        return (0);
    return (1);
}

static user_t *get_user(server_t *server, char *username)
{
    list_t list = list_get_first_node_with_value(server->users, username, &if_user_equal);
    user_t *user;

    if (list)
        return ((user_t *)(list->value));
    user = create_user(username);
    if (!user)
        return (NULL);
    if (!list_add_elem_at_back(&server->users, user))
        return (NULL);
    // server_event_user_created(user->uuid, user->username);
    return (user);
}

int command_login(server_t *server, client_t *client, client_request_t *req, char *data)
{
    char *username = data;
    user_t *user = get_user(server, username);

    if (!user)
        return (FAILURE);
    user->status = 1;
    client->user = user;
    if (send_header_reply(EVENT_LOGGED_IN, DEFAULT_NAME_LENGTH + 16, client) < 0)
        return (FAILURE);
    if (!smart_buffer_add_data(client->write_buf, user->username, DEFAULT_NAME_LENGTH))
        return (FAILURE);
    if (!smart_buffer_add_data(client->write_buf, user->uuid, 16))
        return (FAILURE);
    (void)req;
    return (SUCCESS);
}
