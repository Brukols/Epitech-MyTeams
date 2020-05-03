/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** command_help
*/

#include "server.h"

static const char *response =
"[HELP]\n"
"\t/help : show help\n"
"\t/login [\"username\"] : set the username used by client\n"
"\t/logout : disconnect the client from the server\n"
"\t/users : get the list of all users that exist on the domain\n"
"\t/user [\"user_uuid\"] : get information about a user\n"
"\t/send [\"user_uuid\"] [\"message_body\"] : send a message to a user\n"
"\t/messages [\"user_uuid\"] : list all messages exchange with an user\n"
"\t/subscribe [\"team_uuid\"] : subscribe to the event of a team and its sub \
directories\n"
"\t/subscribed ?[\"team_uuid\"] : list all subscribed teams or list all users \
subscribed to a team\n"
"\t/unsubscribe [\"team_uuid\"] : unsubscribe from a team\n"
"\t/use ?[\"team_uuid\"] ?[\"channel_uuid\"] ?[\"thread_uuid\"] : use specify \
a context team/channel/thread\n"
"\t/create : based on what is being used create the sub resource\n"
"\t/list : based on what is being used list all the sub resources\n"
"\t/info : based on what is being used list the current\n";

int command_help(server_t *server, client_t *client, client_request_t *req, \
char *data)
{
    server_reply_t header = {COMMAND_OK, strlen(response)};

    if (!smart_buffer_add_data(client->write_buf, &header, \
sizeof(server_reply_t)))
        return (FAILURE);
    if (!smart_buffer_add_string(client->write_buf, response))
        return (FAILURE);
    (void)server;
    (void)req;
    (void)data;
    return (SUCCESS);
}
