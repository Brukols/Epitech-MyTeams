/*
** EPITECH PROJECT, 2020
** my teams
** File description:
** saving utils
*/

#include "saving_utils.h"
#include <sys/stat.h>

bool check_and_create_directory(const char *dir)
{
    struct stat s;

    if (stat(dir, &s))
        if (mkdir(dir, 0664))
            return (false);
        return (true);
    return (S_ISDIR(s.st_mode));
}
