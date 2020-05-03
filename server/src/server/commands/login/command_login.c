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
    char uuid[37] = {0};

    if (list)
        return ((user_t *)(list->value));
    user = create_user(username);
    if (!user)
        return (NULL);
    if (!list_add_elem_at_back(&server->users, user))
        return (NULL);
    uuid_unparse(user->uuid, uuid);
    server_event_user_created(uuid, user->username);
    return (user);
}

static int send_response(server_t *server, char *username, uuid_t uuid)
{
    for (list_t clients = server->client; clients; clients = clients->next) {
        client_t *client = (client_t *)clients->value;

        if (!client->user)
            continue;
        if (send_header_reply(EVENT_LOGGED_IN, DEFAULT_NAME_LENGTH + 16, client) < 0)
            return (FAILURE);
        if (!smart_buffer_add_data(client->write_buf, username, DEFAULT_NAME_LENGTH))
            return (FAILURE);
        if (!smart_buffer_add_data(client->write_buf, uuid, 16))
            return (FAILURE);
    }
    return (SUCCESS);
}

int command_login(server_t *server, client_t *client, client_request_t *req, char *data)
{
    char *username = data;
    user_t *user;
    char uuid[37];

    if (req->message_size != DEFAULT_NAME_LENGTH)
        return (send_error_arguments(client, "Invalid length name"));
    if (client->user)
        return (send_response(server, client->user->username, client->user->uuid));
    user = get_user(server, username);
    if (!user)
        return (FAILURE);
    client->user = user;
    uuid_unparse(user->uuid, uuid);
    if (user->nb_clients == 0)
        server_event_user_logged_in(uuid);
    user->nb_clients++;
    (void)req;
    return (send_response(server, user->username, user->uuid));
}
