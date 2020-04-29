/*
** EPITECH PROJECT, 2020
** my teams
** File description:
** smart buffer
*/

#include "smart_buffer.h"

static void smart_buffer_fill_write_buffer(
    const smart_buffer_t *buff,
    char buffer[SMART_BUFFER_MAX_WRITE],
    size_t *size)
{
    size_t pos = buff->start;

    *size = smart_buffer_get_size(buff);
    if (*size > SMART_BUFFER_MAX_WRITE)
        *size = SMART_BUFFER_MAX_WRITE;
    for (size_t i = 0; i < *size; i++) {
        buffer[i] = buff->buffer[pos];
        pos++;
        if (pos == SMART_BUFFER_SIZE)
            pos = 0;
    }
}

ssize_t smart_buffer_write(smart_buffer_t *buffer, int fd)
{
    static char to_write[SMART_BUFFER_MAX_WRITE];
    size_t size = 0;
    ssize_t ret;

    smart_buffer_fill_write_buffer(buffer, to_write, &size);
    ret = write(fd, to_write, size);
    if (ret > 0) {
        buffer->start += ret;
        if (buffer->start >= SMART_BUFFER_SIZE)
            buffer->start -= SMART_BUFFER_SIZE;
    }
    return (ret);
}

ssize_t smart_buffer_read(smart_buffer_t *buffer, int fd)
{
    static char read_buffer[SMART_BUFFER_SIZE];
    size_t size = SMART_BUFFER_SIZE - smart_buffer_get_size(buffer);
    ssize_t ret = read(fd, read_buffer, size);

    if (ret > 0)
        smart_buffer_add_data(buffer, read_buffer, ret);
    return (ret);
}
