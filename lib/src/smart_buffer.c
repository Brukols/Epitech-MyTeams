/*
** EPITECH PROJECT, 2020
** my teams
** File description:
** smart buffer
*/

#include "smart_buffer.h"

smart_buffer_t *smart_buffer_create(void)
{
    smart_buffer_t *ret = malloc(sizeof(smart_buffer_t));

    if (!ret)
        return (NULL);
    *ret = (smart_buffer_t){0};
    return (ret);
}

void smart_buffer_destroy(smart_buffer_t *smart_buffer)
{
    free(smart_buffer->buffer);
    free(smart_buffer);
}

bool smart_buffer_add_string(smart_buffer_t *buffer, const char *str)
{
    return (smart_buffer_add_data(buffer, str, strlen(str)));
}

bool smart_buffer_add_data(smart_buffer_t *buff, const void *data, size_t size)
{
    if (smart_buffer_get_size(buff) + size > SMART_BUFFER_SIZE)
        return (false);
    for (size_t i = 0; i < size; i++) {
        buff->buffer[buff->end] = (const char *){data}[i];
        buff->end++;
        if (buff->end == SMART_BUFFER_SIZE)
            buff->end = 0;
    }
    return (true);
}

size_t smart_buffer_get_size(const smart_buffer_t *buffer)
{
    ssize_t size = buffer->end - buffer->start;

    if (size < 0)
        size += SMART_BUFFER_SIZE;
    return (size);
}

bool smart_buffer_get_data(smart_buffer_t *buff, void *var, size_t size)
{
    if (size > smart_buffer_get_size(buff))
        return (false);
    for (size_t i = 0; i < size; i++) {
        (char *){var}[i] = buff->buffer[buff->start];
        buff->start++;
        if (buff->start == SMART_BUFFER_SIZE)
            buff->start = 0;
    }
    return (true);
}

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
