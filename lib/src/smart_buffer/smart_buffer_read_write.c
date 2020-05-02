/*
** EPITECH PROJECT, 2020
** my teams
** File description:
** smart buffer
*/

#include "smart_buffer.h"

ssize_t smart_buffer_write(smart_buffer_t *buff, int fd)
{
    size_t size = buff->end;
    ssize_t ret;

    if (size > SMART_BUFFER_MAX_WRITE)
        size = SMART_BUFFER_MAX_WRITE;
    ret = write(fd, buff->buffer, size);
    if (ret > 0) {
        buff->end -= ret;
        buff->buffer = memmove(buff->buffer, buff->buffer + ret, buff->end);
    }
    return (ret);
}

ssize_t smart_buffer_read(smart_buffer_t *buffer, int fd)
{
    static char read_buffer[SMART_BUFFER_MAX_READ];
    ssize_t ret = read(fd, read_buffer, SMART_BUFFER_MAX_READ);

    if (ret > 0)
        smart_buffer_add_data(buffer, read_buffer, ret);
    return (ret);
}
