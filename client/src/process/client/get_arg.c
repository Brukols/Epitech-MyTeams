/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** TODO: add description
*/

#include "myteams_client.h"

int get_arg_nb(const char *command)
{
    int nb = 0;

    for (int i = 0; command[i]; i++) {
        if (command[i] == '"')
            nb++;
    };
    if (nb % 2 == 0)
        return (nb / 2);
    return (-1);
}

int get_arg_size(const char *command, int arg_no)
{
    int begin = 1 + arg_no * 2;
    int actual = 0;
    int size = 0;
    int i = 0;

    for (i = 0; command[i] && actual <= begin; i++) {
        if (actual == begin && command[i] != '"') {
            size++;
        }
        if (command[i] == '"')
            actual++;
    }
    return (size);
}

bool get_arg(const char *command, char *buf, int size, int arg_no)
{
    int begin = 1 + arg_no * 2;
    int actual = 0;
    int size_copied = 0;
    int i = 0;

    for (i = 0; command[i] && actual <= begin && size_copied < size; i++) {
        if (actual == begin && command[i] != '"') {
            buf[size_copied] = command[i];
            size_copied++;
        }
        if (command[i] == '"')
            actual++;
    }
    if (actual <= begin && command[i] == '"')
        actual++;
    if (actual <= begin || size_copied == 0)
        return (false);
    return (true);
}