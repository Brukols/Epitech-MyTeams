/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** reply_code
*/

#ifndef REPLY_CODE_H_
#define REPLY_CODE_H_

#define DEFAULT_NAME_LENGTH 32
#define DEFAULT_UUID_LENGTH 32
#define DEFAULT_DESCRIPTION_LENGTH 255
#define DEFAULT_BODY_LENGTH 512

enum command_code_e {
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

enum reply_code_e {
    COMMAND_OK = 200,
    PRINT_USER = 201,
    PRINT_USERS = 202,
    PRINT_TEAM = 210,
    PRINT_CHANNEL = 211,
    PRINT_THREAD = 212,
    PRINT_PRIVATE_MESSAGES = 220,
    PRINT_TEAMS = 230,
    PRINT_CHANNELS = 231,
    PRINT_THREADS = 232,
    PRINT_REPLIES = 233,
    PRINT_SUBSCRIBED = 240,
    PRINT_UNSUBSCRIBED = 241,
    PRINT_TEAM_CREATED = 250,
    PRINT_CHANNEL_CREATED = 251,
    PRINT_THREAD_CREATED = 252,
    PRINT_REPLY_CREATED = 253,

    EVENT_TEAM_CREATED = 311,
    EVENT_CHANNEL_CREATED = 312,
    EVENT_THREAD_CREATED = 313,
    EVENT_THREAD_MESSAGE_RECEIVED = 320,
    EVENT_PRIVATE_MESSAGE_RECEIVED = 321,
    EVENT_LOGGED_IN = 330,
    EVENT_LOGGED_OUT = 331,

    SYNTAX_ERROR = 500,
    SYNTAX_ERROR_ARGS = 501,
    NOT_IMPLEMENTED = 502,
    BAD_SEQUENCE = 503,
    NOT_IMPLEMENTED_ARG = 504,
    NOT_LOGGED_IN = 530,
    CLIENT_ALREADY_EXISTS = 540,
    UNKNOWN_COMMAND = 550,
    UNKNOWN_TEAM = 551,
    UNKNOWN_CHANNEL = 552,
    UNKNOWN_THREAD = 553,
    UNKNOWN_USER = 554,
    UNAUTHORIZED = 560,
};

#endif /* !REPLY_CODE_H_ */
