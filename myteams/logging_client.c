#include <time.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#define PRINT(msg, ...) (fprintf(stderr, msg, __VA_ARGS__))
#define PRINT_AND_RETURN(msg, ...) return (PRINT(msg, __VA_ARGS__) >= 0 ? 1 : -1)

int client_event_loggedin(char const * user_id, const char *user_name)
{
    PRINT_AND_RETURN("Client %s logged in with login %s\n", user_id, user_name);
}

int client_event_private_message_received(char const * user_id, char const *message)
{
    PRINT_AND_RETURN("New private message from %s:\n%s\n", user_id, message);
}

int client_event_thread_message_received(char const * team_id, char const * thread_id, char const * user_id, char const *message)
{
    PRINT_AND_RETURN("New message from %s in thread %s of team %s:\n%s\n", user_id, thread_id, team_id, message);
}

int client_print_users(char const * user_id, char const *name, int connected)
{
    PRINT_AND_RETURN("User \"%s\" (%s): %d\n", name, user_id, connected);
}

int client_print_teams(char const * team_id, char const *name, char const *description)
{
    PRINT_AND_RETURN("Team \"%s\" (%s): %s\n", name, team_id, description);
}

int client_team_print_channels(char const * channel_id, char const *name, char const *description)
{
    PRINT_AND_RETURN("Channel \"%s\" (%s): %s\n", name, channel_id, description);
}

int client_channel_print_threads(char const * thread_id, char const * user_id, time_t timestamp, char const *title, char const *message)
{
    int ret = PRINT("[Thread %s] Created by %s (%s):\n%s\n--------------\n%s\n", thread_id, user_id, ctime(&timestamp), title, message);
    return (ret);
}

int client_thread_print_replies(char const * thread_id, char const * user_id, time_t timestamp, char const *message)
{
    int ret = PRINT("[Thread %s] %s (%s):\n%s\n", thread_id, user_id, ctime(&timestamp), message);
    return (ret);
}

int client_private_message_print_messages(char const * sender_id, time_t timestamp, char const *message)
{
    int ret = PRINT("[Private] %s (%s): %s\n", sender_id, ctime(&timestamp), message);
    return (ret);
}

int client_error_unknown_team(char const * team_id)
{
    PRINT_AND_RETURN("Unknown team %s\n", team_id);
}

int client_error_unknown_channel(char const * channel_id)
{
    PRINT_AND_RETURN("Unknown channel %s\n", channel_id);
}

int client_error_unknown_thread(char const * thread_id)
{
    PRINT_AND_RETURN("Unknown thread %s\n", thread_id);
}

int client_error_unknown_user(char const * user_id)
{
    PRINT_AND_RETURN("Unknown user %s\n", user_id);
}

#undef PRINT_AND_RETURN
#undef PRINT
