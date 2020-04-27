#ifndef __LOGGING_CLIENT_H__
#define __LOGGING_CLIENT_H__

#include <stdint.h>
#include <time.h>

//! Handler called when the connection to the server is done
/*!
	\param user_id an unsigned integer corresponding to the unique identifier assigned to the currently logged user
	\param user_name a character pointer corresponding to the user name.
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately 
*/
int client_event_loggedin(char const *user_id, const char *user_name);

//! Handler called when a new private message is received
/*!
	\param user_id an unsigned integer corresponding to the unique identifier assigned to the user who sended the message.
	\param team_name a character pointer corresponding to the message.
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately 
*/
int client_event_private_message_received(char const *user_id, char const *message);

//! Handler called when a new reply is post in a thread
/*!
	\param thread_id an unsigned integer corresponding to the unique identifier assigned to the thread hosting the reply.
	\param user_id an unsigned integer corresponding to the unique identifier assigned to the user who sended the message.
	\param team_name a character pointer corresponding to the message.
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately 
*/
int client_event_thread_message_received(char const *team_id, char const *thread_id, char const *user_id, char const *message);

//! Handler called when the user ask for the users list (/users CLI command), used in a loop over each team
/*!
	\param user_id an unsigned integer corresponding to the unique identifier assigned to the user.
	\param user_name a character pointer corresponding to the user's name.
	\param user_status an integer corresponding to the user status (0 = not connected; 1 = connected).
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately 
*/
int client_print_users(char const *team_id, char const *name, int connected);

//! Handler called when the user ask for the team list (/list CLI command), used in a loop over each team
/*!
	\param team_id an unsigned integer corresponding to the unique identifier assigned to the team.
	\param team_name a character pointer corresponding to the team's name.
	\param team_description a character pointer corresponding to the team's description.
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately 
*/
int client_print_teams(char const *team_id, char const *name, char const *description);


//! Handler called when the user select a specific team to be in (/team CLI command), used in a loop over each channel
/*!
	\param channel_id an unsigned integer corresponding to the unique identifier assigned to the channel in the team.
	\param name a character pointer corresponding to the channel's name.
	\param description a character pointer corresponding to the channel's description.
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately 
*/
int client_team_print_channels(char const *channel_id, char const *name, char const *description);

//! Handler called when the user select a specific channel to be in (/channel CLI command), used in a loop over each thread
/*!
	\param thread_id an unsigned integer corresponding to the unique identifier assigned to the thread in the team.
	\param user_id an unsigned integer corresponding to the unique identifier assigned to the user who created the thread.
	\param timestamp an unsigned integer corresponding to the timestamp of the thread's creation.
	\param message a character pointer corresponding to the message.
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately 
*/
int client_channel_print_threads(char const *thread_id, char const *user_id, time_t timestamp, char const *title, char const *message);

//! Handler called when the user ask for a specific thread (/thread CLI command), used in a loop over each reply
/*!
	\param thread_id an unsigned integer corresponding to the unique identifier assigned to the thread in the channel.
	\param user_id an unsigned integer corresponding to the unique identifier assigned to the user who created the thread.
	\param timestamp an unsigned integer corresponding to the timestamp of the message.
	\param title a character pointer corresponding to the thread's title.
	\param message a character pointer corresponding to the message.
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately 
*/
int client_thread_print_replies(char const *thread_id, char const *user_id, time_t timestamp, char const *message);

//! Handler called when the user ask for a specific private discussion (/messages CLI command), used in a loop over each message
/*!
	\param sender_id an unsigned integer corresponding to the unique identifier assigned to the user sending the message
	\param timestamp an unsigned integer corresponding to the timestamp of the message.
	\param message a character pointer corresponding to the message.
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately 
*/
int client_private_message_print_messages(char const *sender_id, time_t timestamp, char const *message);

//! Handler called when the user ask for an unkown specific team (/team CLI command)
/*!
	\param team_id an unsigned integer corresponding to the WRONG team identifier 
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately 
*/
int client_error_unknown_team(char const *team_id);

//! Handler called when the user ask for an unkown specific channel (/channel CLI command)
/*!
	\param channel_id an unsigned integer corresponding to the WRONG channel identifier 
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately 
*/
int client_error_unknown_channel(char const *channel_id);

//! Handler called when the user ask for an unkown specific thread (/thread CLI command)
/*!
	\param thread_id an unsigned integer corresponding to the WRONG thread identifier 
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately 
*/
int client_error_unknown_thread(char const *thread_id);

//! Handler called when the user want to chat with an unkown user (/messages and /send CLI command)
/*!
	\param user_id an unsigned integer corresponding to the WRONG user identifier 
	\return On success, 1 is returned. On error, -1 is returned and errno is set appropriately 
*/
int client_error_unknown_user(char const *user_id);


#endif /* __LOGGING_CLIENT_H__ */
