#include <stdint.h>
#include <time.h>
#include <stdio.h>

#define PRINT(msg, ...) (fprintf(stderr, msg, __VA_ARGS__))
#define PRINT_AND_RETURN(msg, ...) return (PRINT(msg, __VA_ARGS__) >= 0 ? 1 : -1)

int server_event_team_created(char const *team_id, char const *team_name, char const *user_id)
{
    PRINT_AND_RETURN("User %s created Team \"%s\" (%s).\n", user_id, team_name, team_id);
}

int server_event_channel_created(char const *team_id, char const *channel_id, char const *channel_name)
{
    PRINT_AND_RETURN("Channel \"%s\" (%s) created in team %s.\n", channel_name, channel_id, team_id);
}

int server_event_thread_created(char const *channel_id, char const *thread_id, char const *user_id, char const *message)
{
    PRINT_AND_RETURN("New thread %s in channel %s.\nNew message in thread (%s) from %s: %s\n", thread_id, channel_id, thread_id, user_id, message);
}

int server_event_thread_new_message(char const *thread_id, char const *user_id, char const *message)
{
    PRINT_AND_RETURN("New message in thread (%s) from %s: %s\n", thread_id, user_id, message);
}

int server_event_user_join_a_team(char const *team_id, char const *user_id)
{
    PRINT_AND_RETURN("User %s joined team %s.\n", user_id, team_id);
}

int server_event_user_leave_a_team(char const *team_id, char const *user_id)
{
    PRINT_AND_RETURN("User %s leaved team %s.\n", user_id, team_id);
}

int server_event_user_created(char const *user_id, char const *user_name)
{
    PRINT_AND_RETURN("New user: %s (%s).\n", user_name, user_id);
}

int server_event_user_loaded(char const *user_id, char const *user_name)
{
    PRINT_AND_RETURN("User loaded: %s (%s).\n", user_name, user_id);
}

int server_event_user_logged_in(char const *user_id)
{
    PRINT_AND_RETURN("User %s logged in.\n", user_id);
}

int server_event_user_logged_out(char const *user_id)
{
    PRINT_AND_RETURN("User %s logged out.\n", user_id);
}

int server_event_private_message_sended(char const *sender_id, char const *receiver_id, char const *message)
{
    PRINT_AND_RETURN("Private message %s->%s: %s\n", sender_id, receiver_id, message);
}

#undef PRINT_AND_RETURN
#undef PRINT
