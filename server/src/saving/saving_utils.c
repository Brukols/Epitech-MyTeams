/*
** EPITECH PROJECT, 2020
** my teams
** File description:
** saving utils
*/

#include "saving_utils.h"
#include <sys/stat.h>
#include <sys/fcntl.h>

int get_data_fd(const char *dir)
{
    char data_fp[256];

    strcpy(data_fp, dir);
    strcat(data_fp, "/.data");
    return (open(data_fp, O_WRONLY | O_CREAT | O_TRUNC, 0664));
}

int get_meta_fd(const char *dir)
{
    char meta_fp[256];

    strcpy(meta_fp, dir);
    strcat(meta_fp, "/.meta");
    return (open(meta_fp, O_WRONLY | O_CREAT | O_TRUNC, 0664));
}

bool write_buffer(int fd, const char *buffer, size_t size)
{
    ssize_t ret = 0;
    size_t written = 0;

    do {
        ret = write(fd, buffer + written, size - written);
        if (ret == -1)
            return (false);
        written += ret;
    } while (written < size);
    return (true);
}

bool check_and_create_directory(const char *dir)
{
    struct stat s;

    if (stat(dir, &s)) {
        if (mkdir(dir, 0775))
            return (false);
        return (true);
    }
    return (S_ISDIR(s.st_mode));
}
