/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** TODO: add description
*/

#include <dirent.h>
#include "server.h"

bool ignore_directory(struct dirent *dp)
{
    if (dp->d_type != DT_DIR || strcmp(dp->d_name, ".") == 0
        || strcmp(dp->d_name, "..") == 0)
        return (true);
    return (false);
}