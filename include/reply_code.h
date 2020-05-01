/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** reply_code
*/

#ifndef REPLY_CODE_H_
#define REPLY_CODE_H_

#define DEFAULT_NAME_LENGTH 32
#define DEFAULT_DESCRIPTION_LENGTH 255
#define DEFAULT_BODY_LENGTH 512

enum reply_code_e {
    UNKNOWN,
    HELP,
    LOGIN,
    LOGOUT,
    USERS,
    USER,
    SEND,
    MESSAGES,
    SUBSCRIBE,
    SUBSCRIBED,
    UNSUBSCRIBE,
    USE,
    CREATE,
    LIST,
    INFO
};

#endif /* !REPLY_CODE_H_ */
