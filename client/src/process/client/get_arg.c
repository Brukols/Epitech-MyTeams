/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** TODO: add description
*/

#include "myteams_client.h"

bool get_arg(const char *command, char *buf, int size, int arg_no)
{
    int begin = 1 + arg_no * 2;
    int actual = 0;
    int size_copied = 0;

    for (int i = 0; command[i] && actual <= begin && size_copied <= size; i++) {
        if (actual == begin && command[i] != '"' && size_copied < size) {
            buf[size_copied] = command[i];
            size_copied++;
        }
        if (command[i] == '"')
            actual++;
    }
    if (actual <= begin || size_copied == 0)
        return (false);
    return (true);
}