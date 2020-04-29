/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** TODO: add description
*/

#include "message_t.h"

char *tcp_get_message2(char *line, char *buffer, int i, int j)
{
    char *newline = NULL;
    int len = 0;

    if (line != 0) {
        len = strlen(line);
        newline = malloc(sizeof(char) * (len + j + 1));
        if (newline == NULL)
            return (NULL);
        strncpy(newline, line, len);
    } else {
        newline = malloc(sizeof(char) * (len + j + 1));
        if (newline == NULL)
            return (NULL);
    }
    newline[len + j] = '\0';
    strncpy(newline + len, buffer + i, j);
    free(line);
    return (newline);
}

char* tcp_get_message(int socket)
{
    static char buffer[TCP_READ_SIZE];
    static int size = 1;
    static int i = 1;
    char *line = NULL;
    for (int j = 0, new = 1; new != 0; j++) {
        if (size <= i) {
            i = j = 0;
            new = size = read(socket, buffer, TCP_READ_SIZE);
            buffer[size] = '\0';
        }
        if (buffer[i + j] == '\r' && new > 0) {
            line = tcp_get_message2(line, buffer, i, j);
            i = i + j + 1;
            return (line);
        } else if (buffer[i + j] == '\0' && new > 0) {
            line = tcp_get_message2(line, buffer, i, j + 1);
            i = size;
        }
    }
    return (line);
}