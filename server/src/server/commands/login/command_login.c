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

static user_t *get_user(server_t *server, client_t *client, char *username)
{
    user_t *user = (user_t *)list_get_first_node_with_value(server->users, username, &if_user_equal);

    if (user) {
        if (!list_add_elem_at_back(&user->client, client))
            return (NULL);
        if (!list_del_elem_at_value(&server->client, client, NULL))
            return (NULL);
        return (user);
    }
    user = create_user(username);
    if (!user)
        return (NULL);
    if (!list_add_elem_at_back(&server->users, user))
        return (NULL);
    if (!list_add_elem_at_back(&user->client, client))
        return (NULL);
    if (!list_del_elem_at_value(&server->client, client, NULL))
        return (NULL);
    // server_event_user_created(user->uuid, user->username);
    return (user);
}

int command_login(server_t *server, client_t *client, client_request_t *req, char *data)
{
    char *username = data;
    user_t *user = get_user(server, client, username);

    if (!user)
        return (FAILURE);
    if (send_header_reply(300, strlen(user->username) + 16, client) < 0)
        return (FAILURE);
    if (!smart_buffer_add_string(client->write_buf, user->username))
        return (FAILURE);
    if (!smart_buffer_add_data(client->write_buf, user->uuid, 16))
        return (FAILURE);
    (void)req;
    return (SUCCESS);
}